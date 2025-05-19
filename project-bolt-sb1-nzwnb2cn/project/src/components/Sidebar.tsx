import React from 'react';
import { NavLink } from 'react-router-dom';
import { 
  LayoutDashboard, 
  Users, 
  Bell, 
  Megaphone, 
  FileText, 
  BarChart3, 
  Settings, 
  HelpCircle,
  LogOut 
} from 'lucide-react';
import { currentUser } from '../data/mockData';

const Sidebar: React.FC = () => {
  const navLinkClass = ({ isActive }: { isActive: boolean }) => 
    `flex items-center px-4 py-3 text-sm ${
      isActive 
        ? 'bg-blue-700 text-white' 
        : 'text-gray-300 hover:bg-blue-800 hover:text-white'
    } rounded-md transition-colors`;

  return (
    <div className="w-64 bg-gray-900 text-white flex flex-col h-full">
      <div className="p-4 border-b border-gray-800">
        <div className="flex items-center space-x-2">
          <LayoutDashboard className="h-8 w-8 text-violet-400" />
          <div>
            <h1 className="text-xl font-semibold">Conseiller Augmenté</h1>
            <p className="text-xs text-gray-400">AI Insurance Assistant</p>
          </div>
        </div>
      </div>
      
      <div className="p-4 border-b border-gray-800">
        <div className="flex items-center space-x-3">
          <img 
            src={currentUser.avatar} 
            alt={currentUser.name} 
            className="w-10 h-10 rounded-full object-cover"
          />
          <div>
            <p className="font-medium text-sm">{currentUser.name}</p>
            <p className="text-xs text-gray-400">{currentUser.role}</p>
          </div>
        </div>
      </div>
      
      <nav className="flex-1 p-4 space-y-1 overflow-y-auto">
        <NavLink to="/" className={navLinkClass}>
          <LayoutDashboard className="h-5 w-5 mr-3" />
          Dashboard
        </NavLink>
        <NavLink to="/clients" className={navLinkClass}>
          <Users className="h-5 w-5 mr-3" />
          Clients
        </NavLink>
        <NavLink to="/notifications" className={navLinkClass}>
          <Bell className="h-5 w-5 mr-3" />
          Notifications
        </NavLink>
        <NavLink to="/campaigns" className={navLinkClass}>
          <Megaphone className="h-5 w-5 mr-3" />
          Campaigns
        </NavLink>
        
        <div className="pt-4 mt-4 border-t border-gray-800">
          <p className="px-4 text-xs font-medium text-gray-400 uppercase tracking-wider mb-2">
            Analytics
          </p>
          <NavLink to="/reports" className={navLinkClass}>
            <FileText className="h-5 w-5 mr-3" />
            Reports
          </NavLink>
          <NavLink to="/analytics" className={navLinkClass}>
            <BarChart3 className="h-5 w-5 mr-3" />
            Analytics
          </NavLink>
        </div>
      </nav>
      
      <div className="p-4 border-t border-gray-800">
        <NavLink to="/settings" className={navLinkClass}>
          <Settings className="h-5 w-5 mr-3" />
          Settings
        </NavLink>
        <NavLink to="/help" className={navLinkClass}>
          <HelpCircle className="h-5 w-5 mr-3" />
          Help & Support
        </NavLink>
        <button className="flex items-center w-full px-4 py-3 mt-2 text-sm text-gray-300 hover:bg-red-700 hover:text-white rounded-md transition-colors">
          <LogOut className="h-5 w-5 mr-3" />
          Logout
        </button>
      </div>
    </div>
  );
};

export default Sidebar;