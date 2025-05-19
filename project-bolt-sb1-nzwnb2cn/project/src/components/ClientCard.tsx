import React from 'react';
import { Link } from 'react-router-dom';
import { ArrowRight, Phone, Mail, Clock, AlertTriangle } from 'lucide-react';
import { Client } from '../types';

interface ClientCardProps {
  client: Client;
  compact?: boolean;
}

const ClientCard: React.FC<ClientCardProps> = ({ client, compact = false }) => {
  const fullName = `${client.firstName} ${client.lastName}`;
  
  const getRiskColor = (score: number) => {
    if (score < 25) return 'bg-green-100 text-green-800';
    if (score < 50) return 'bg-yellow-100 text-yellow-800';
    return 'bg-red-100 text-red-800';
  };
  
  const getStatusColor = (status: string) => {
    switch (status) {
      case 'prospect': return 'bg-blue-100 text-blue-800';
      case 'active': return 'bg-green-100 text-green-800';
      case 'dormant': return 'bg-gray-100 text-gray-800';
      default: return 'bg-gray-100 text-gray-800';
    }
  };
  
  if (compact) {
    return (
      <Link to={`/client/${client.id}`} className="block hover:bg-gray-50">
        <div className="flex items-center p-4 border-b border-gray-200">
          <div className="flex-shrink-0 mr-3">
            {client.profilePicture ? (
              <img 
                src={client.profilePicture} 
                alt={fullName} 
                className="h-10 w-10 rounded-full object-cover"
              />
            ) : (
              <div className="h-10 w-10 rounded-full bg-gray-300 flex items-center justify-center text-gray-600">
                {client.firstName.charAt(0)}{client.lastName.charAt(0)}
              </div>
            )}
          </div>
          <div className="flex-1 min-w-0">
            <p className="text-sm font-medium text-gray-900 truncate">{fullName}</p>
            <p className="text-xs text-gray-500 truncate">{client.email}</p>
          </div>
          <div>
            <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium ${getStatusColor(client.status)}`}>
              {client.status}
            </span>
          </div>
          <ArrowRight className="ml-2 h-4 w-4 text-gray-400" />
        </div>
      </Link>
    );
  }
  
  return (
    <div className="bg-white rounded-lg shadow-sm overflow-hidden border border-gray-200 hover:shadow-md transition-shadow">
      <div className="p-4">
        <div className="flex items-center justify-between mb-3">
          <div className="flex items-center">
            {client.profilePicture ? (
              <img 
                src={client.profilePicture} 
                alt={fullName} 
                className="h-12 w-12 rounded-full object-cover mr-3"
              />
            ) : (
              <div className="h-12 w-12 rounded-full bg-gray-300 flex items-center justify-center text-gray-600 mr-3">
                {client.firstName.charAt(0)}{client.lastName.charAt(0)}
              </div>
            )}
            <div>
              <h3 className="text-base font-semibold text-gray-900">{fullName}</h3>
              <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium ${getStatusColor(client.status)}`}>
                {client.status}
              </span>
            </div>
          </div>
          <div className="text-right">
            <div className={`px-2 py-1 rounded text-xs font-medium ${getRiskColor(client.riskScore)}`}>
              Risk Score: {client.riskScore}
            </div>
            {client.lifetimeValue > 0 && (
              <div className="text-xs text-gray-500 mt-1">
                Lifetime: €{client.lifetimeValue.toLocaleString()}
              </div>
            )}
          </div>
        </div>
        
        <div className="space-y-2 mb-3">
          <div className="flex items-center text-xs text-gray-600">
            <Mail className="h-3.5 w-3.5 mr-1.5" />
            <span className="truncate">{client.email}</span>
          </div>
          <div className="flex items-center text-xs text-gray-600">
            <Phone className="h-3.5 w-3.5 mr-1.5" />
            <span>{client.phone}</span>
          </div>
          {client.lastContact && (
            <div className="flex items-center text-xs text-gray-600">
              <Clock className="h-3.5 w-3.5 mr-1.5" />
              <span>Last contact: {new Date(client.lastContact).toLocaleDateString()}</span>
            </div>
          )}
        </div>
        
        <div className="border-t border-gray-100 pt-3 mt-3">
          <div className="flex justify-between items-center">
            <div>
              <span className="text-xs font-medium text-gray-500">
                {client.products.length} Product{client.products.length !== 1 ? 's' : ''}
              </span>
              {client.claims.length > 0 && (
                <span className="ml-2 inline-flex items-center text-xs font-medium text-amber-600">
                  <AlertTriangle className="h-3 w-3 mr-1" />
                  {client.claims.length} Claim{client.claims.length !== 1 ? 's' : ''}
                </span>
              )}
            </div>
            <Link 
              to={`/client/${client.id}`}
              className="text-xs font-medium text-blue-600 hover:text-blue-800 flex items-center"
            >
              View profile
              <ArrowRight className="ml-1 h-3.5 w-3.5" />
            </Link>
          </div>
        </div>
      </div>
    </div>
  );
};

export default ClientCard;