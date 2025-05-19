import React from 'react';
import { Calendar, Users, CheckCircle, ExternalLink } from 'lucide-react';
import { Campaign } from '../types';

interface CampaignCardProps {
  campaign: Campaign;
}

const CampaignCard: React.FC<CampaignCardProps> = ({ campaign }) => {
  const getStatusColor = (status: string) => {
    switch (status) {
      case 'active': return 'bg-green-100 text-green-800';
      case 'completed': return 'bg-blue-100 text-blue-800';
      case 'scheduled': return 'bg-yellow-100 text-yellow-800';
      case 'draft': return 'bg-gray-100 text-gray-600';
      default: return 'bg-gray-100 text-gray-600';
    }
  };
  
  const getProductIcon = (type: string) => {
    switch (type) {
      case 'auto': return '🚗';
      case 'home': return '🏠';
      case 'life': return '👪';
      case 'health': return '⚕️';
      case 'retirement': return '🏖️';
      case 'multi': return '📦';
      default: return '📄';
    }
  };
  
  const conversionRate = campaign.metrics.sent > 0 
    ? ((campaign.metrics.converted / campaign.metrics.sent) * 100).toFixed(1) 
    : '0.0';
  
  return (
    <div className="bg-white rounded-lg shadow-sm overflow-hidden border border-gray-200 module-green">
      <div className="p-4">
        <div className="flex items-center justify-between mb-3">
          <div className="flex items-center">
            <span className="text-2xl mr-3">{getProductIcon(campaign.productType)}</span>
            <div>
              <h3 className="text-base font-semibold">{campaign.name}</h3>
              <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium ${getStatusColor(campaign.status)}`}>
                {campaign.status.charAt(0).toUpperCase() + campaign.status.slice(1)}
              </span>
            </div>
          </div>
        </div>
        
        <p className="text-sm text-gray-700 mb-3 line-clamp-2">{campaign.message}</p>
        
        <div className="flex flex-wrap gap-y-2 text-xs text-gray-600 mb-3">
          <div className="flex items-center w-full sm:w-1/2">
            <Calendar className="h-3.5 w-3.5 mr-1.5" />
            <span>
              {new Date(campaign.startDate).toLocaleDateString()} 
              {campaign.endDate ? ` - ${new Date(campaign.endDate).toLocaleDateString()}` : ''}
            </span>
          </div>
          <div className="flex items-center w-full sm:w-1/2">
            <Users className="h-3.5 w-3.5 mr-1.5" />
            <span>{campaign.targetAudience}</span>
          </div>
        </div>
        
        {campaign.status !== 'draft' && (
          <div className="border-t border-gray-100 pt-3 mt-3">
            <h4 className="text-xs font-medium text-gray-700 mb-2">Campaign Metrics</h4>
            <div className="grid grid-cols-4 gap-2 text-center">
              <div className="bg-gray-50 rounded p-2">
                <div className="text-sm font-semibold">{campaign.metrics.sent}</div>
                <div className="text-xs text-gray-500">Sent</div>
              </div>
              <div className="bg-gray-50 rounded p-2">
                <div className="text-sm font-semibold">{campaign.metrics.opened}</div>
                <div className="text-xs text-gray-500">Opened</div>
              </div>
              <div className="bg-gray-50 rounded p-2">
                <div className="text-sm font-semibold">{campaign.metrics.clicked}</div>
                <div className="text-xs text-gray-500">Clicked</div>
              </div>
              <div className="bg-blue-50 rounded p-2">
                <div className="text-sm font-semibold text-blue-700">{campaign.metrics.converted}</div>
                <div className="text-xs text-blue-600">Converted</div>
              </div>
            </div>
            
            <div className="flex justify-between items-center mt-3 text-xs">
              <span className="text-gray-600">Conversion rate</span>
              <span className="font-medium">{conversionRate}%</span>
            </div>
            <div className="w-full bg-gray-200 rounded-full h-1.5 mt-1">
              <div 
                className="bg-blue-600 h-1.5 rounded-full" 
                style={{ width: `${Math.min(100, parseFloat(conversionRate) * 5)}%` }}
              ></div>
            </div>
          </div>
        )}
        
        <div className="flex justify-between items-center mt-3 pt-3 border-t border-gray-100">
          {campaign.status === 'draft' ? (
            <button className="text-xs text-blue-600 hover:text-blue-800 flex items-center">
              <CheckCircle className="h-3.5 w-3.5 mr-1" />
              Finalize Campaign
            </button>
          ) : (
            <button className="text-xs text-blue-600 hover:text-blue-800 flex items-center">
              <ExternalLink className="h-3.5 w-3.5 mr-1" />
              View Report
            </button>
          )}
          
          <button className="px-3 py-1.5 bg-white border border-gray-300 rounded text-xs hover:bg-gray-50">
            Edit Campaign
          </button>
        </div>
      </div>
    </div>
  );
};

export default CampaignCard;