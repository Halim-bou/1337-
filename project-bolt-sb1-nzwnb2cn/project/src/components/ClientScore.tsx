import React from 'react';
import { Client } from '../types';

interface ClientScoreProps {
  client: Client;
}

const ClientScore: React.FC<ClientScoreProps> = ({ client }) => {
  // Determine colors based on risk score
  const getRiskColor = (score: number) => {
    if (score < 25) return { bg: 'bg-green-500', text: 'text-green-700' };
    if (score < 50) return { bg: 'bg-yellow-500', text: 'text-yellow-700' };
    return { bg: 'bg-red-500', text: 'text-red-700' };
  };
  
  const { bg: riskBg, text: riskText } = getRiskColor(client.riskScore);
  
  // Calculate engagement score (mock)
  const engagementScore = Math.min(100, Math.max(0, 85 - client.riskScore + (client.products.length * 10)));
  
  // Calculate retention probability (mock)
  const retentionProbability = Math.min(100, Math.max(0, 90 - client.riskScore / 2 + (client.products.length * 5)));
  
  // Determine expansion potential (mock)
  let expansionPotential = 'Medium';
  let expansionColor = 'text-yellow-600';
  
  if (client.products.length < 1 && client.riskScore < 40) {
    expansionPotential = 'High';
    expansionColor = 'text-green-600';
  } else if (client.products.length > 2 || client.riskScore > 70) {
    expansionPotential = 'Low';
    expansionColor = 'text-red-600';
  }
  
  return (
    <div className="bg-white rounded-lg shadow-sm border border-gray-200 p-4 module-violet">
      <h3 className="text-base font-semibold mb-3">Client AI Analysis</h3>
      
      <div className="space-y-4">
        <div>
          <div className="flex justify-between mb-1">
            <span className="text-sm text-gray-600">Risk Score</span>
            <span className={`text-sm font-medium ${riskText}`}>{client.riskScore}%</span>
          </div>
          <div className="w-full bg-gray-200 rounded-full h-2">
            <div className={`${riskBg} h-2 rounded-full`} style={{ width: `${client.riskScore}%` }}></div>
          </div>
          <p className="text-xs text-gray-500 mt-1">
            Based on claim history, payment patterns, and demographic factors
          </p>
        </div>
        
        <div>
          <div className="flex justify-between mb-1">
            <span className="text-sm text-gray-600">Engagement Score</span>
            <span className="text-sm font-medium text-blue-700">{engagementScore}%</span>
          </div>
          <div className="w-full bg-gray-200 rounded-full h-2">
            <div className="bg-blue-500 h-2 rounded-full" style={{ width: `${engagementScore}%` }}></div>
          </div>
          <p className="text-xs text-gray-500 mt-1">
            Based on communication frequency, response rate, and app usage
          </p>
        </div>
        
        <div>
          <div className="flex justify-between mb-1">
            <span className="text-sm text-gray-600">Retention Probability</span>
            <span className="text-sm font-medium text-indigo-700">{retentionProbability}%</span>
          </div>
          <div className="w-full bg-gray-200 rounded-full h-2">
            <div className="bg-indigo-500 h-2 rounded-full" style={{ width: `${retentionProbability}%` }}></div>
          </div>
          <p className="text-xs text-gray-500 mt-1">
            Likelihood of maintaining relationship for next 12 months
          </p>
        </div>
        
        <div className="flex justify-between items-center pt-2 border-t border-gray-100">
          <span className="text-sm text-gray-600">Expansion Potential</span>
          <span className={`text-sm font-medium ${expansionColor}`}>{expansionPotential}</span>
        </div>
        
        <div className="flex justify-between items-center pt-2 border-t border-gray-100">
          <span className="text-sm text-gray-600">Lifetime Value</span>
          <span className="text-sm font-medium">€{client.lifetimeValue.toLocaleString()}</span>
        </div>
      </div>
    </div>
  );
};

export default ClientScore;