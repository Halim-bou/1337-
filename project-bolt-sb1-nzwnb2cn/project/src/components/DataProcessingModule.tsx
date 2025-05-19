import React from 'react';
import { FileUp, RefreshCw, CheckCircle, XCircle } from 'lucide-react';
import { OCRResult } from '../types';

interface DataProcessingModuleProps {
  clientId?: string;
}

const DataProcessingModule: React.FC<DataProcessingModuleProps> = ({ clientId }) => {
  const [selectedFile, setSelectedFile] = React.useState<File | null>(null);
  const [processing, setProcessing] = React.useState(false);
  const [results, setResults] = React.useState<OCRResult | null>(null);
  
  const handleFileChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    if (e.target.files && e.target.files.length > 0) {
      setSelectedFile(e.target.files[0]);
    }
  };
  
  const processDocument = () => {
    if (!selectedFile) return;
    
    setProcessing(true);
    
    // Simulate processing delay
    setTimeout(() => {
      // Mock OCR result
      const mockResult: OCRResult = {
        fullName: 'Jean Martin Dupont',
        dateOfBirth: '15/05/1982',
        idNumber: '820515AB12345',
        expiryDate: '10/06/2030',
        address: '15 Rue de la Paix, 75001 Paris',
        confidence: 92.5
      };
      
      setResults(mockResult);
      setProcessing(false);
    }, 2500);
  };
  
  const resetForm = () => {
    setSelectedFile(null);
    setResults(null);
  };
  
  return (
    <div className="bg-white rounded-lg shadow-sm border border-gray-200 p-4 module-blue">
      <h3 className="text-base font-semibold mb-3">Document Processing</h3>
      
      {!results ? (
        <>
          <div className="mb-4">
            <label className="block text-sm font-medium text-gray-700 mb-1">
              Upload ID Document
            </label>
            <div className="mt-1 flex justify-center px-6 pt-5 pb-6 border-2 border-gray-300 border-dashed rounded-md">
              <div className="space-y-1 text-center">
                <FileUp className="mx-auto h-12 w-12 text-gray-400" />
                <div className="flex text-sm text-gray-600">
                  <label
                    htmlFor="file-upload"
                    className="relative cursor-pointer bg-white rounded-md font-medium text-blue-600 hover:text-blue-500 focus-within:outline-none"
                  >
                    <span>Upload a file</span>
                    <input
                      id="file-upload"
                      name="file-upload"
                      type="file"
                      className="sr-only"
                      accept="image/*,.pdf"
                      onChange={handleFileChange}
                    />
                  </label>
                  <p className="pl-1">or drag and drop</p>
                </div>
                <p className="text-xs text-gray-500">
                  ID card, passport, or driver's license
                </p>
              </div>
            </div>
          </div>
          
          {selectedFile && (
            <div className="mb-4 p-3 bg-gray-50 rounded-md">
              <div className="flex items-center justify-between">
                <div className="flex items-center">
                  <CheckCircle className="h-5 w-5 text-green-500 mr-2" />
                  <span className="text-sm">{selectedFile.name}</span>
                </div>
                <button 
                  onClick={() => setSelectedFile(null)}
                  className="text-sm text-gray-500 hover:text-gray-700"
                >
                  <XCircle className="h-4 w-4" />
                </button>
              </div>
            </div>
          )}
          
          <div className="flex justify-end">
            <button
              type="button"
              className="flex items-center px-4 py-2 border border-transparent text-sm font-medium rounded-md shadow-sm text-white bg-blue-600 hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500 disabled:opacity-50 disabled:cursor-not-allowed"
              disabled={!selectedFile || processing}
              onClick={processDocument}
            >
              {processing ? (
                <>
                  <RefreshCw className="animate-spin h-4 w-4 mr-2" />
                  Processing...
                </>
              ) : (
                <>Process Document</>
              )}
            </button>
          </div>
        </>
      ) : (
        <div className="space-y-4 fade-in">
          <div className="flex justify-between items-center mb-2">
            <h4 className="text-sm font-medium">Extracted Information</h4>
            <span className="px-2 py-1 bg-green-100 text-green-800 text-xs rounded-full">
              {results.confidence.toFixed(1)}% confidence
            </span>
          </div>
          
          <div className="space-y-3">
            <div>
              <p className="text-xs text-gray-500">Full Name</p>
              <p className="text-sm font-medium">{results.fullName}</p>
            </div>
            <div className="grid grid-cols-2 gap-4">
              <div>
                <p className="text-xs text-gray-500">Date of Birth</p>
                <p className="text-sm font-medium">{results.dateOfBirth}</p>
              </div>
              <div>
                <p className="text-xs text-gray-500">ID Number</p>
                <p className="text-sm font-medium">{results.idNumber}</p>
              </div>
            </div>
            <div>
              <p className="text-xs text-gray-500">Address</p>
              <p className="text-sm font-medium">{results.address}</p>
            </div>
            <div>
              <p className="text-xs text-gray-500">ID Expiry Date</p>
              <p className="text-sm font-medium">{results.expiryDate}</p>
            </div>
          </div>
          
          <div className="pt-3 flex justify-between border-t border-gray-200">
            <button
              type="button"
              className="text-sm text-gray-600 hover:text-gray-900"
              onClick={resetForm}
            >
              Process another document
            </button>
            
            <button
              type="button"
              className="flex items-center px-4 py-2 border border-transparent text-sm font-medium rounded-md shadow-sm text-white bg-green-600 hover:bg-green-700 focus:outline-none"
            >
              Verify & Save
            </button>
          </div>
        </div>
      )}
    </div>
  );
};

export default DataProcessingModule;