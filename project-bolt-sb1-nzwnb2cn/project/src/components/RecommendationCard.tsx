import React, { useState } from 'react';
import { ChevronDown, ChevronUp } from 'lucide-react';
import { Recommendation } from '../types';

interface RecommendationCardProps {
  recommendation: Recommendation;
}

const RecommendationCard: React.FC<RecommendationCardProps> = ({ recommendation }) => {
  const [expanded, setExpanded] = useState(false);
  
  const getScoreColor = (score: number) => {
    if (score >= 85) return 'text-green-600';
    if (score >= 70) return 'text-yellow-600';
    return 'text-amber-600';
  };
  
  const getProductIcon = (type: string) => {
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
    <div className="bg-white rounded-lg shadow-sm overflow-hidden border border-gray-200 module-violet mb-4">
      <div className="p-4">
        <div className="flex justify-between items-start">
          <div className="flex items-center">
            <span className="text-2xl mr-3">{getProductIcon(recommendation.productType)}</span>
            <div>
              <h3 className="text-base font-semibold">{recommendation.name}</h3>
              <p className="text-sm text-gray-600">{recommendation.description}</p>
            </div>
          </div>
          <div className="text-right">
            <div className={`text-lg font-semibold ${getScoreColor(recommendation.score)}`}>
              {recommendation.score}%
            </div>
            <div className="text-sm text-gray-700">Match Score</div>
          </div>
        </div>
        
        <div className="flex justify-between items-center mt-3 pt-3 border-t border-gray-100">
          <div className="text-sm">
            <span className="font-medium">€{recommendation.premium}</span>
            <span className="text-gray-500">/month</span>
          </div>
          <button 
            onClick={() => setExpanded(!expanded)}
            className="flex items-center text-sm text-blue-600 hover:text-blue-800"
          >
            {expanded ? (
              <>
                Hide details
                <ChevronUp className="ml-1 h-4 w-4" />
              </>
            ) : (
              <>
                Show details
                <ChevronDown className="ml-1 h-4 w-4" />
              </>
            )}
          </button>
        </div>
        
        {expanded && (
          <div className="mt-3 pt-3 border-t border-gray-100 text-sm fade-in">
            <h4 className="font-medium mb-2">Why we recommend this:</h4>
            <ul className="list-disc list-inside text-gray-700 space-y-1 ml-2">
              {recommendation.reasoning.map((reason, index) => (
                <li key={index}>{reason}</li>
              ))}
            </ul>
            
            {recommendation.potentialSavings && recommendation.potentialSavings > 0 && (
              <div className="mt-3 bg-green-50 p-2 rounded text-green-800">
                <span className="font-medium">Potential savings: </span>
                €{recommendation.potentialSavings}/year
              </div>
            )}
            
            {recommendation.additionalCoverage && recommendation.additionalCoverage.length > 0 && (
              <div className="mt-3">
                <h4 className="font-medium mb-1">Additional coverage:</h4>
                <ul className="list-disc list-inside text-gray-700 space-y-0.5 ml-2">
                  {recommendation.additionalCoverage.map((coverage, index) => (
                    <li key={index}>{coverage}</li>
                  ))}
                </ul>
              </div>
            )}
            
            <div className="mt-3 flex justify-between">
              <button className="px-3 py-1.5 bg-white border border-gray-300 rounded text-sm hover:bg-gray-50">
                Compare Options
              </button>
              <button className="px-3 py-1.5 bg-blue-600 text-white rounded text-sm hover:bg-blue-700">
                Propose to Client
              </button>
            </div>
          </div>
        )}
      </div>
    </div>
  );
};

export default RecommendationCard;