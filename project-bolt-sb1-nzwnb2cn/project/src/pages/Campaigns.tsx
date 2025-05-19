import React, { useState } from 'react';
import { Plus, Filter } from 'lucide-react';
import { campaigns } from '../data/mockData';
import CampaignCard from '../components/CampaignCard';

const Campaigns: React.FC = () => {
  const [filter, setFilter] = useState<string>('all');
  
  const filteredCampaigns = campaigns.filter(campaign => {
    if (filter === 'all') return true;
    return campaign.status === filter;
  });
  
  return (
    <div className="space-y-6">
      <div className="flex justify-between items-center">
        <h1 className="text-2xl font-bold text-gray-900">Marketing Campaigns</h1>
        <button className="flex items-center px-4 py-2 bg-blue-600 text-white rounded-md shadow-sm text-sm font-medium hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500">
          <Plus className="h-4 w-4 mr-2" />
          New Campaign
        </button>
      </div>
      
      {/* Filter Bar */}
      <div className="bg-white p-3 rounded-lg shadow-sm border border-gray-200 flex flex-wrap items-center gap-2">
        <div className="flex items-center mr-2">
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
          All Campaigns
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
          onClick={() => setFilter('scheduled')}
          className={`px-3 py-1 rounded-md text-sm ${
            filter === 'scheduled' 
              ? 'bg-blue-600 text-white' 
              : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
          }`}
        >
          Scheduled
        </button>
        
        <button
          onClick={() => setFilter('completed')}
          className={`px-3 py-1 rounded-md text-sm ${
            filter === 'completed' 
              ? 'bg-blue-600 text-white' 
              : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
          }`}
        >
          Completed
        </button>
        
        <button
          onClick={() => setFilter('draft')}
          className={`px-3 py-1 rounded-md text-sm ${
            filter === 'draft' 
              ? 'bg-blue-600 text-white' 
              : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
          }`}
        >
          Drafts
        </button>
      </div>
      
      {/* Campaigns Grid */}
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6">
        {filteredCampaigns.map(campaign => (
          <CampaignCard key={campaign.id} campaign={campaign} />
        ))}
      </div>
      
      {filteredCampaigns.length === 0 && (
        <div className="bg-white rounded-lg shadow-sm border border-gray-200 p-8 text-center">
          <h3 className="text-lg font-medium text-gray-900 mb-1">No campaigns found</h3>
          <p className="text-gray-500 mb-4">
            {filter === 'all' 
              ? "You don't have any campaigns yet" 
              : `No ${filter} campaigns found`}
          </p>
          <button className="inline-flex items-center px-4 py-2 bg-blue-600 text-white rounded-md shadow-sm text-sm font-medium hover:bg-blue-700 focus:outline-none">
            <Plus className="h-4 w-4 mr-2" />
            Create your first campaign
          </button>
        </div>
      )}
    </div>
  );
};

export default Campaigns;