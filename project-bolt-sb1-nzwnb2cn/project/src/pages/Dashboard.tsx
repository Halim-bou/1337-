import React from 'react';
import { Doughnut, Bar } from 'react-chartjs-2';
import { 
  Chart as ChartJS, 
  ArcElement, 
  CategoryScale, 
  LinearScale,
  BarElement,
  Title, 
  Tooltip, 
  Legend 
} from 'chart.js';
import { Link } from 'react-router-dom';
import { 
  ArrowRight, 
  Bell, 
  Calendar, 
  Users, 
  Wallet, 
  BarChart3, 
  TrendingUp 
} from 'lucide-react';
import { clients, notifications, campaigns } from '../data/mockData';
import ClientCard from '../components/ClientCard';
import CampaignCard from '../components/CampaignCard';

ChartJS.register(
  ArcElement,
  CategoryScale,
  LinearScale,
  BarElement,
  Title,
  Tooltip,
  Legend
);

const Dashboard: React.FC = () => {
  // Get upcoming renewals (next 30 days)
  const today = new Date();
  const thirtyDaysLater = new Date();
  thirtyDaysLater.setDate(today.getDate() + 30);
  
  // Filter for recent clients (last contacted within 14 days)
  const recentClients = clients.filter(client => 
    client.lastContact && new Date(client.lastContact) >= new Date(today.getTime() - 14 * 24 * 60 * 60 * 1000)
  ).slice(0, 3);
  
  // Chart data for product distribution
  const productData = {
    labels: ['Auto', 'Home', 'Life', 'Health', 'Retirement'],
    datasets: [
      {
        data: [42, 28, 15, 10, 5],
        backgroundColor: [
          'rgba(59, 130, 246, 0.8)',
          'rgba(16, 185, 129, 0.8)',
          'rgba(139, 92, 246, 0.8)',
          'rgba(239, 68, 68, 0.8)',
          'rgba(245, 158, 11, 0.8)',
        ],
        borderColor: [
          'rgba(59, 130, 246, 1)',
          'rgba(16, 185, 129, 1)',
          'rgba(139, 92, 246, 1)',
          'rgba(239, 68, 68, 1)',
          'rgba(245, 158, 11, 1)',
        ],
        borderWidth: 1,
      },
    ],
  };
  
  // Chart data for monthly performance
  const performanceData = {
    labels: ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun'],
    datasets: [
      {
        label: 'New Policies',
        data: [12, 19, 15, 22, 24, 18],
        backgroundColor: 'rgba(59, 130, 246, 0.5)',
      },
      {
        label: 'Renewals',
        data: [15, 12, 18, 14, 22, 16],
        backgroundColor: 'rgba(16, 185, 129, 0.5)',
      },
    ],
  };
  
  const chartOptions = {
    responsive: true,
    maintainAspectRatio: false,
    plugins: {
      legend: {
        position: 'bottom' as const,
      },
    },
  };
  
  return (
    <div className="space-y-6">
      <div className="flex justify-between items-center">
        <h1 className="text-2xl font-bold text-gray-900">Dashboard</h1>
        <div className="text-sm text-gray-500">
          {today.toLocaleDateString('en-US', { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' })}
        </div>
      </div>
      
      {/* Stats Overview */}
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-4">
        <div className="bg-white p-4 rounded-lg shadow-sm border border-gray-200">
          <div className="flex items-center justify-between">
            <div>
              <p className="text-sm text-gray-500">Client Portfolio</p>
              <p className="text-2xl font-bold">{clients.length}</p>
            </div>
            <div className="p-3 bg-blue-100 rounded-full">
              <Users className="h-6 w-6 text-blue-600" />
            </div>
          </div>
          <div className="mt-2 text-xs flex items-center text-green-600">
            <TrendingUp className="h-3 w-3 mr-1" />
            +3 this month
          </div>
        </div>
        
        <div className="bg-white p-4 rounded-lg shadow-sm border border-gray-200">
          <div className="flex items-center justify-between">
            <div>
              <p className="text-sm text-gray-500">Active Policies</p>
              <p className="text-2xl font-bold">10</p>
            </div>
            <div className="p-3 bg-green-100 rounded-full">
              <Wallet className="h-6 w-6 text-green-600" />
            </div>
          </div>
          <div className="mt-2 text-xs flex items-center text-green-600">
            <TrendingUp className="h-3 w-3 mr-1" />
            +2 this month
          </div>
        </div>
        
        <div className="bg-white p-4 rounded-lg shadow-sm border border-gray-200">
          <div className="flex items-center justify-between">
            <div>
              <p className="text-sm text-gray-500">Pending Renewals</p>
              <p className="text-2xl font-bold">3</p>
            </div>
            <div className="p-3 bg-yellow-100 rounded-full">
              <Calendar className="h-6 w-6 text-yellow-600" />
            </div>
          </div>
          <div className="mt-2 text-xs flex items-center text-amber-600">
            Due in next 30 days
          </div>
        </div>
        
        <div className="bg-white p-4 rounded-lg shadow-sm border border-gray-200">
          <div className="flex items-center justify-between">
            <div>
              <p className="text-sm text-gray-500">New Notifications</p>
              <p className="text-2xl font-bold">{notifications.filter(n => !n.read).length}</p>
            </div>
            <div className="p-3 bg-red-100 rounded-full">
              <Bell className="h-6 w-6 text-red-600" />
            </div>
          </div>
          <div className="mt-2 text-xs">
            <Link to="/notifications" className="text-blue-600 hover:text-blue-800">
              View all notifications
            </Link>
          </div>
        </div>
      </div>
      
      {/* Recent Activity and Charts */}
      <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">
        {/* Recent Clients */}
        <div className="lg:col-span-2">
          <div className="bg-white rounded-lg shadow-sm border border-gray-200 overflow-hidden">
            <div className="px-4 py-3 border-b border-gray-200 flex justify-between items-center">
              <h2 className="text-base font-semibold">Recent Client Activity</h2>
              <Link 
                to="/clients" 
                className="text-sm text-blue-600 hover:text-blue-800 flex items-center"
              >
                View all
                <ArrowRight className="h-4 w-4 ml-1" />
              </Link>
            </div>
            <div>
              {recentClients.length > 0 ? (
                recentClients.map(client => (
                  <ClientCard key={client.id} client={client} compact />
                ))
              ) : (
                <div className="p-4 text-center text-gray-500">
                  No recent client activity
                </div>
              )}
            </div>
          </div>
          
          {/* Performance Chart */}
          <div className="mt-6 bg-white rounded-lg shadow-sm border border-gray-200 overflow-hidden">
            <div className="px-4 py-3 border-b border-gray-200">
              <h2 className="text-base font-semibold">Monthly Performance</h2>
            </div>
            <div className="p-4" style={{ height: '250px' }}>
              <Bar data={performanceData} options={chartOptions} />
            </div>
          </div>
        </div>
        
        {/* Right Column */}
        <div className="space-y-6">
          {/* Product Distribution */}
          <div className="bg-white rounded-lg shadow-sm border border-gray-200 overflow-hidden">
            <div className="px-4 py-3 border-b border-gray-200">
              <h2 className="text-base font-semibold">Product Distribution</h2>
            </div>
            <div className="p-4" style={{ height: '250px' }}>
              <Doughnut data={productData} options={chartOptions} />
            </div>
          </div>
          
          {/* Current Campaigns */}
          <div className="bg-white rounded-lg shadow-sm border border-gray-200 overflow-hidden">
            <div className="px-4 py-3 border-b border-gray-200 flex justify-between items-center">
              <h2 className="text-base font-semibold">Active Campaigns</h2>
              <Link 
                to="/campaigns" 
                className="text-sm text-blue-600 hover:text-blue-800 flex items-center"
              >
                View all
                <ArrowRight className="h-4 w-4 ml-1" />
              </Link>
            </div>
            <div className="p-4">
              {campaigns.filter(c => c.status === 'active').length > 0 ? (
                campaigns.filter(c => c.status === 'active').slice(0, 1).map(campaign => (
                  <CampaignCard key={campaign.id} campaign={campaign} />
                ))
              ) : (
                <div className="text-center text-gray-500">
                  No active campaigns
                </div>
              )}
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Dashboard;