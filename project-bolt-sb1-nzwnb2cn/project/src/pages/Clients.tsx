import React, { useState } from 'react';
import { Plus, Filter, Search } from 'lucide-react';
import { clients } from '../data/mockData';
import ClientCard from '../components/ClientCard';

const Clients: React.FC = () => {
  const [filter, setFilter] = useState<string>('all');
  const [searchQuery, setSearchQuery] = useState('');
  
  const filteredClients = clients.filter(client => {
    const matchesFilter = filter === 'all' || client.status === filter;
    const matchesSearch = searchQuery.toLowerCase() === '' || 
      `${client.firstName} ${client.lastName}`.toLowerCase().includes(searchQuery.toLowerCase()) ||
      client.email.toLowerCase().includes(searchQuery.toLowerCase());
    
    return matchesFilter && matchesSearch;
  });
  
  return (
    <div className="space-y-6">
      <div className="flex justify-between items-center">
        <h1 className="text-2xl font-bold text-gray-900">Clients</h1>
        <button className="flex items-center px-4 py-2 bg-blue-600 text-white rounded-md shadow-sm text-sm font-medium hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500">
          <Plus className="h-4 w-4 mr-2" />
          Add New Client
        </button>
      </div>
      
      {/* Search and Filter Bar */}
      <div className="bg-white p-4 rounded-lg shadow-sm border border-gray-200 space-y-4">
        <div className="relative">
          <input
            type="text"
            placeholder="Search clients by name or email..."
            value={searchQuery}
            onChange={(e) => setSearchQuery(e.target.value)}
            className="w-full pl-10 pr-4 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-blue-500"
          />
          <Search className="absolute left-3 top-2.5 h-5 w-5 text-gray-400" />
        </div>
        
        <div className="flex items-center gap-2">
          <div className="flex items-center">
            <Filter className="h-4 w-4 text-gray-500 mr-1" />
            <span className="text-sm text-gray-500">Filter:</span>
          </div>
          
          <button
            onClick={() => setFilter('all')}
            className={`px-3 py-1 rounded-md text-sm ${
              filter === 'all' 
                ? 'bg-blue-600 text-white' 
                : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
            }`}
          >
            All Clients
          </button>
          
          <button
            onClick={() => setFilter('active')}
            className={`px-3 py-1 rounded-md text-sm ${
              filter === 'active' 
                ? 'bg-blue-600 text-white' 
                : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
            }`}
          >
            Active
          </button>
          
          <button
            onClick={() => setFilter('prospect')}
            className={`px-3 py-1 rounded-md text-sm ${
              filter === 'prospect' 
                ? 'bg-blue-600 text-white' 
                : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
            }`}
          >
            Prospects
          </button>
          
          <button
            onClick={() => setFilter('dormant')}
            className={`px-3 py-1 rounded-md text-sm ${
              filter === 'dormant' 
                ? 'bg-blue-600 text-white' 
                : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
            }`}
          >
            Dormant
          </button>
        </div>
      </div>
      
      {/* Clients Grid */}
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6">
        {filteredClients.map(client => (
          <ClientCard key={client.id} client={client} />
        ))}
      </div>
      
      {filteredClients.length === 0 && (
        <div className="bg-white rounded-lg shadow-sm border border-gray-200 p-8 text-center">
          <h3 className="text-lg font-medium text-gray-900 mb-1">No clients found</h3>
          <p className="text-gray-500 mb-4">
            {searchQuery 
              ? "No clients match your search criteria" 
              : filter === 'all' 
                ? "You don't have any clients yet" 
                : `No ${filter} clients found`}
          </p>
          <button className="inline-flex items-center px-4 py-2 bg-blue-600 text-white rounded-md shadow-sm text-sm font-medium hover:bg-blue-700 focus:outline-none">
            <Plus className="h-4 w-4 mr-2" />
            Add your first client
          </button>
        </div>
      )}
    </div>
  );
};

export default Clients;