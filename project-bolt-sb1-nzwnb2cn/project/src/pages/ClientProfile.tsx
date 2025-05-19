import React from 'react';
import { useParams, Link } from 'react-router-dom';
import { 
  ArrowLeft, 
  Phone, 
  Mail, 
  Calendar, 
  Clock, 
  MapPin, 
  AlertTriangle,
  FileText,
  MessageSquare,
  Edit
} from 'lucide-react';
import { clients, recommendations } from '../data/mockData';
import RecommendationCard from '../components/RecommendationCard';
import ClientScore from '../components/ClientScore';
import DataProcessingModule from '../components/DataProcessingModule';

const ClientProfile: React.FC = () => {
  const { id } = useParams<{ id: string }>();
  const client = clients.find(c => c.id === id);
  
  if (!client) {
    return (
      <div className="text-center py-10">
        <h2 className="text-xl font-semibold mb-2">Client Not Found</h2>
        <p className="text-gray-600 mb-4">The client you are looking for does not exist.</p>
        <Link to="/" className="text-blue-600 hover:text-blue-800 flex items-center justify-center">
          <ArrowLeft className="h-4 w-4 mr-1" />
          Back to Dashboard
        </Link>
      </div>
    );
  }
  
  const fullName = `${client.firstName} ${client.lastName}`;
  const clientRecommendations = recommendations[client.id] || [];
  
  const getStatusColor = (status: string) => {
    switch (status) {
      case 'prospect': return 'bg-blue-100 text-blue-800';
      case 'active': return 'bg-green-100 text-green-800';
      case 'dormant': return 'bg-gray-100 text-gray-800';
      default: return 'bg-gray-100 text-gray-800';
    }
  };
  
  const getProductTypeIcon = (type: string) => {
    switch (type) {
      case 'auto':
        return '🚗';
      case 'home':
        return '🏠';
      case 'life':
        return '👪';
      case 'health':
        return '⚕️';
      case 'retirement':
        return '🏖️';
      default:
        return '📄';
    }
  };
  
  return (
    <div>
      <div className="mb-6">
        <Link to="/" className="text-blue-600 hover:text-blue-800 flex items-center text-sm">
          <ArrowLeft className="h-4 w-4 mr-1" />
          Back to Dashboard
        </Link>
      </div>
      
      {/* Client Header */}
      <div className="bg-white rounded-lg shadow-sm border border-gray-200 p-4 mb-6">
        <div className="flex flex-col sm:flex-row items-start sm:items-center justify-between mb-4">
          <div className="flex items-center mb-3 sm:mb-0">
            {client.profilePicture ? (
              <img 
                src={client.profilePicture} 
                alt={fullName} 
                className="h-16 w-16 rounded-full object-cover mr-4"
              />
            ) : (
              <div className="h-16 w-16 rounded-full bg-gray-300 flex items-center justify-center text-gray-600 mr-4 text-xl">
                {client.firstName.charAt(0)}{client.lastName.charAt(0)}
              </div>
            )}
            <div>
              <h1 className="text-2xl font-bold">{fullName}</h1>
              <div className="flex items-center mt-1">
                <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium ${getStatusColor(client.status)}`}>
                  {client.status.charAt(0).toUpperCase() + client.status.slice(1)}
                </span>
                <span className="mx-2 text-gray-300">•</span>
                <span className="text-sm text-gray-500">Client since {new Date().getFullYear() - 2}</span>
              </div>
            </div>
          </div>
          
          <div className="flex space-x-2">
            <button className="flex items-center px-3 py-2 border border-gray-300 rounded text-sm font-medium text-gray-700 bg-white hover:bg-gray-50">
              <Phone className="h-4 w-4 mr-2" />
              Call
            </button>
            <button className="flex items-center px-3 py-2 border border-gray-300 rounded text-sm font-medium text-gray-700 bg-white hover:bg-gray-50">
              <Mail className="h-4 w-4 mr-2" />
              Email
            </button>
            <button className="flex items-center px-3 py-2 border border-gray-300 rounded text-sm font-medium text-gray-700 bg-white hover:bg-gray-50">
              <Edit className="h-4 w-4 mr-2" />
              Edit
            </button>
          </div>
        </div>
        
        <div className="grid grid-cols-1 md:grid-cols-3 gap-4 border-t border-gray-200 pt-4">
          <div className="flex items-start">
            <Mail className="h-5 w-5 text-gray-400 mt-0.5 mr-2" />
            <div>
              <p className="text-xs text-gray-500">Email</p>
              <p className="text-sm">{client.email}</p>
            </div>
          </div>
          <div className="flex items-start">
            <Phone className="h-5 w-5 text-gray-400 mt-0.5 mr-2" />
            <div>
              <p className="text-xs text-gray-500">Phone</p>
              <p className="text-sm">{client.phone}</p>
            </div>
          </div>
          <div className="flex items-start">
            <Calendar className="h-5 w-5 text-gray-400 mt-0.5 mr-2" />
            <div>
              <p className="text-xs text-gray-500">Date of Birth</p>
              <p className="text-sm">{new Date(client.birthDate).toLocaleDateString()}</p>
            </div>
          </div>
          <div className="flex items-start">
            <MapPin className="h-5 w-5 text-gray-400 mt-0.5 mr-2" />
            <div>
              <p className="text-xs text-gray-500">Address</p>
              <p className="text-sm">{client.address}</p>
            </div>
          </div>
          <div className="flex items-start">
            <Clock className="h-5 w-5 text-gray-400 mt-0.5 mr-2" />
            <div>
              <p className="text-xs text-gray-500">Last Contact</p>
              <p className="text-sm">{client.lastContact ? new Date(client.lastContact).toLocaleDateString() : 'Never'}</p>
            </div>
          </div>
          <div className="flex items-start">
            <FileText className="h-5 w-5 text-gray-400 mt-0.5 mr-2" />
            <div>
              <p className="text-xs text-gray-500">Products</p>
              <p className="text-sm">{client.products.length} active product{client.products.length !== 1 ? 's' : ''}</p>
            </div>
          </div>
        </div>
      </div>
      
      {/* Main Content */}
      <div className="grid grid-cols-1 md:grid-cols-3 gap-6">
        {/* Left Column - Client Details */}
        <div className="md:col-span-2 space-y-6">
          {/* AI Recommendations */}
          <div className="bg-white rounded-lg shadow-sm border border-gray-200 p-4">
            <h2 className="text-lg font-semibold mb-4">AI Recommendations</h2>
            
            {clientRecommendations.length > 0 ? (
              <div className="space-y-4">
                {clientRecommendations.map(recommendation => (
                  <RecommendationCard 
                    key={recommendation.id} 
                    recommendation={recommendation}
                  />
                ))}
              </div>
            ) : (
              <div className="text-center py-6 text-gray-500">
                <p>No recommendations available for this client.</p>
              </div>
            )}
          </div>
          
          {/* Products */}
          <div className="bg-white rounded-lg shadow-sm border border-gray-200 p-4">
            <h2 className="text-lg font-semibold mb-4">Current Products</h2>
            
            {client.products.length > 0 ? (
              <div className="space-y-4">
                {client.products.map(product => (
                  <div key={product.id} className="border border-gray-200 rounded-md p-4">
                    <div className="flex justify-between items-start">
                      <div className="flex items-center">
                        <span className="text-2xl mr-3">{getProductTypeIcon(product.type)}</span>
                        <div>
                          <h3 className="text-base font-medium">{product.name}</h3>
                          <p className="text-sm text-gray-500">
                            Valid until {new Date(product.endDate).toLocaleDateString()}
                          </p>
                        </div>
                      </div>
                      <div className="text-right">
                        <div className="text-base font-semibold">€{product.premium}/month</div>
                        <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium ${
                          product.status === 'active' ? 'bg-green-100 text-green-800' : 
                          product.status === 'pending' ? 'bg-yellow-100 text-yellow-800' : 
                          'bg-red-100 text-red-800'
                        }`}>
                          {product.status}
                        </span>
                      </div>
                    </div>
                    
                    {product.details && (
                      <div className="mt-3 pt-3 border-t border-gray-100">
                        <h4 className="text-sm font-medium mb-2">Coverage Details</h4>
                        <div className="grid grid-cols-2 gap-x-4 gap-y-2">
                          {Object.entries(product.details).map(([key, value]) => (
                            <div key={key}>
                              <p className="text-xs text-gray-500">{key.charAt(0).toUpperCase() + key.slice(1)}</p>
                              <p className="text-sm">{value}</p>
                            </div>
                          ))}
                        </div>
                      </div>
                    )}
                  </div>
                ))}
              </div>
            ) : (
              <div className="text-center py-6 text-gray-500">
                <p>No products available for this client.</p>
              </div>
            )}
          </div>
        </div>
        
        {/* Right Column - Analytics and Processing */}
        <div className="space-y-6">
          {/* Client AI Analysis */}
          <ClientScore client={client} />
          
          {/* Document Processing */}
          <DataProcessingModule clientId={client.id} />
          
          {/* Interaction History */}
          <div className="bg-white rounded-lg shadow-sm border border-gray-200 p-4">
            <h3 className="text-base font-semibold mb-3">Interaction History</h3>
            
            {client.interactions.length > 0 ? (
              <div className="space-y-3">
                {client.interactions.map(interaction => (
                  <div 
                    key={interaction.id} 
                    className="p-3 border border-gray-200 rounded-md hover:bg-gray-50"
                  >
                    <div className="flex justify-between items-start">
                      <div className="flex items-start">
                        <MessageSquare className="h-4 w-4 text-blue-500 mt-0.5 mr-2" />
                        <div>
                          <p className="text-sm font-medium">
                            {interaction.type.charAt(0).toUpperCase() + interaction.type.slice(1)} via {interaction.channel}
                          </p>
                          <p className="text-xs text-gray-500">
                            {new Date(interaction.date).toLocaleDateString()}
                          </p>
                        </div>
                      </div>
                    </div>
                    <p className="text-sm text-gray-700 mt-1 ml-6">
                      {interaction.summary}
                    </p>
                  </div>
                ))}
              </div>
            ) : (
              <div className="text-center py-4 text-gray-500">
                <p>No interaction history available.</p>
              </div>
            )}
          </div>
          
          {/* Claims History */}
          {client.claims.length > 0 && (
            <div className="bg-white rounded-lg shadow-sm border border-gray-200 p-4">
              <h3 className="text-base font-semibold mb-3">Claims History</h3>
              
              <div className="space-y-3">
                {client.claims.map(claim => (
                  <div 
                    key={claim.id} 
                    className="p-3 border border-gray-200 rounded-md hover:bg-gray-50"
                  >
                    <div className="flex justify-between items-start">
                      <div>
                        <p className="text-sm font-medium flex items-center">
                          <AlertTriangle className="h-4 w-4 text-amber-500 mr-2" />
                          {claim.description}
                        </p>
                        <p className="text-xs text-gray-500 ml-6">
                          {new Date(claim.date).toLocaleDateString()}
                        </p>
                      </div>
                      <div className="text-right">
                        <p className="text-sm font-medium">€{claim.amount.toLocaleString()}</p>
                        <span className={`inline-flex items-center px-2 py-0.5 rounded text-xs font-medium ${
                          claim.status === 'paid' ? 'bg-green-100 text-green-800' : 
                          claim.status === 'approved' ? 'bg-blue-100 text-blue-800' : 
                          claim.status === 'pending' ? 'bg-yellow-100 text-yellow-800' : 
                          'bg-red-100 text-red-800'
                        }`}>
                          {claim.status}
                        </span>
                      </div>
                    </div>
                  </div>
                ))}
              </div>
            </div>
          )}
        </div>
      </div>
    </div>
  );
};

export default ClientProfile;