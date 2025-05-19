import React, { useState } from 'react';
import { Bell, Search, Menu } from 'lucide-react';
import { notifications } from '../data/mockData';

const Header: React.FC = () => {
  const [showNotifications, setShowNotifications] = useState(false);
  
  const unreadCount = notifications.filter(n => !n.read).length;
  
  return (
    <header className="bg-white border-b border-gray-200 px-4 py-3 flex items-center justify-between">
      <div className="flex items-center">
        <button className="mr-4 lg:hidden">
          <Menu className="h-6 w-6 text-gray-600" />
        </button>
        <div className="relative">
          <input
            type="text"
            placeholder="Search clients, products..."
            className="pl-10 pr-4 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-blue-500 w-64 text-sm"
          />
          <Search className="absolute left-3 top-2.5 h-4 w-4 text-gray-400" />
        </div>
      </div>
      
      <div className="flex items-center space-x-4">
        <div className="relative">
          <button 
            className="relative p-2 text-gray-600 hover:text-gray-900 focus:outline-none"
            onClick={() => setShowNotifications(!showNotifications)}
          >
            <Bell className="h-6 w-6" />
            {unreadCount > 0 && (
              <span className="absolute top-1 right-1 bg-red-500 text-white text-xs rounded-full h-4 w-4 flex items-center justify-center">
                {unreadCount}
              </span>
            )}
          </button>
          
          {showNotifications && (
            <div className="absolute right-0 mt-2 w-80 bg-white rounded-md shadow-lg z-10 scale-in">
              <div className="p-3 border-b border-gray-200">
                <h3 className="text-sm font-semibold">Notifications</h3>
              </div>
              <div className="max-h-96 overflow-y-auto">
                {notifications.slice(0, 3).map(notification => (
                  <div 
                    key={notification.id} 
                    className={`p-3 border-b border-gray-100 hover:bg-gray-50 ${
                      !notification.read ? 'bg-blue-50' : ''
                    }`}
                  >
                    <div className="flex items-start">
                      <div className={`h-2 w-2 mt-1 mr-2 rounded-full ${
                        notification.priority === 'high' ? 'bg-red-500' :
                        notification.priority === 'medium' ? 'bg-yellow-500' : 'bg-green-500'
                      }`} />
                      <div className="flex-1">
                        <p className="text-sm font-medium">{notification.title}</p>
                        <p className="text-xs text-gray-600 mt-1">{notification.message}</p>
                        <div className="flex items-center justify-between mt-2">
                          <span className="text-xs text-gray-500">{new Date(notification.date).toLocaleDateString()}</span>
                          {notification.action && (
                            <a href={notification.action.link} className="text-xs text-blue-600 hover:text-blue-800">
                              {notification.action.label}
                            </a>
                          )}
                        </div>
                      </div>
                    </div>
                  </div>
                ))}
              </div>
              <div className="p-2 text-center border-t border-gray-200">
                <a href="/notifications" className="text-xs text-blue-600 hover:text-blue-800">
                  View all notifications
                </a>
              </div>
            </div>
          )}
        </div>
      </div>
    </header>
  );
};

export default Header;