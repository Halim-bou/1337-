import React, { useState } from 'react';
import { Check, Bell, Filter, ArrowDown, ArrowUp } from 'lucide-react';
import { notifications } from '../data/mockData';
import { Notification } from '../types';

const Notifications: React.FC = () => {
  const [filter, setFilter] = useState<string>('all');
  const [sortDirection, setSortDirection] = useState<'asc' | 'desc'>('desc');
  const [selectedNotifications, setSelectedNotifications] = useState<string[]>([]);
  
  const filteredNotifications = notifications.filter(notification => {
    if (filter === 'all') return true;
    if (filter === 'unread') return !notification.read;
    return notification.type === filter;
  });
  
  const sortedNotifications = [...filteredNotifications].sort((a, b) => {
    const dateA = new Date(a.date).getTime();
    const dateB = new Date(b.date).getTime();
    return sortDirection === 'desc' ? dateB - dateA : dateA - dateB;
  });
  
  const toggleSort = () => {
    setSortDirection(sortDirection === 'desc' ? 'asc' : 'desc');
  };
  
  const toggleSelection = (id: string) => {
    if (selectedNotifications.includes(id)) {
      setSelectedNotifications(selectedNotifications.filter(notifId => notifId !== id));
    } else {
      setSelectedNotifications([...selectedNotifications, id]);
    }
  };
  
  const markAsRead = () => {
    // In a real application, this would update the notifications in the backend
    alert(`Marked ${selectedNotifications.length} notifications as read`);
    setSelectedNotifications([]);
  };
  
  const getPriorityColor = (priority: string) => {
    switch (priority) {
      case 'high': return 'bg-red-500';
      case 'medium': return 'bg-yellow-500';
      case 'low': return 'bg-green-500';
      default: return 'bg-gray-500';
    }
  };
  
  const getTypeLabel = (type: string) => {
    switch (type) {
      case 'renewal': return 'Renewal';
      case 'claim': return 'Claim';
      case 'payment': return 'Payment';
      case 'opportunity': return 'Opportunity';
      case 'alert': return 'Alert';
      default: return type.charAt(0).toUpperCase() + type.slice(1);
    }
  };
  
  const getTypeColor = (type: string) => {
    switch (type) {
      case 'renewal': return 'bg-blue-100 text-blue-800';
      case 'claim': return 'bg-yellow-100 text-yellow-800';
      case 'payment': return 'bg-green-100 text-green-800';
      case 'opportunity': return 'bg-purple-100 text-purple-800';
      case 'alert': return 'bg-red-100 text-red-800';
      default: return 'bg-gray-100 text-gray-800';
    }
  };
  
  return (
    <div className="space-y-6">
      <div className="flex justify-between items-center">
        <h1 className="text-2xl font-bold text-gray-900">Notifications</h1>
        <button
          onClick={markAsRead}
          disabled={selectedNotifications.length === 0}
          className="flex items-center px-4 py-2 bg-white border border-gray-300 rounded-md shadow-sm text-sm font-medium text-gray-700 hover:bg-gray-50 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500 disabled:opacity-50 disabled:cursor-not-allowed"
        >
          <Check className="h-4 w-4 mr-2" />
          Mark as Read ({selectedNotifications.length})
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
          All
        </button>
        
        <button
          onClick={() => setFilter('unread')}
          className={`px-3 py-1 rounded-md text-sm ${
            filter === 'unread' 
              ? 'bg-blue-600 text-white' 
              : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
          }`}
        >
          Unread
        </button>
        
        <button
          onClick={() => setFilter('renewal')}
          className={`px-3 py-1 rounded-md text-sm ${
            filter === 'renewal' 
              ? 'bg-blue-600 text-white' 
              : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
          }`}
        >
          Renewals
        </button>
        
        <button
          onClick={() => setFilter('opportunity')}
          className={`px-3 py-1 rounded-md text-sm ${
            filter === 'opportunity' 
              ? 'bg-blue-600 text-white' 
              : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
          }`}
        >
          Opportunities
        </button>
        
        <button
          onClick={() => setFilter('alert')}
          className={`px-3 py-1 rounded-md text-sm ${
            filter === 'alert' 
              ? 'bg-blue-600 text-white' 
              : 'bg-gray-100 text-gray-800 hover:bg-gray-200'
          }`}
        >
          Alerts
        </button>
        
        <div className="ml-auto">
          <button
            onClick={toggleSort}
            className="flex items-center px-3 py-1 bg-white border border-gray-300 rounded-md text-sm hover:bg-gray-50"
          >
            Date {sortDirection === 'desc' ? <ArrowDown className="h-3 w-3 ml-1" /> : <ArrowUp className="h-3 w-3 ml-1" />}
          </button>
        </div>
      </div>
      
      {/* Notifications List */}
      <div className="bg-white rounded-lg shadow-sm border border-gray-200 overflow-hidden">
        {sortedNotifications.length > 0 ? (
          <div>
            {sortedNotifications.map((notification: Notification) => (
              <div 
                key={notification.id} 
                className={`p-4 border-b border-gray-200 hover:bg-gray-50 ${
                  !notification.read ? 'bg-blue-50' : ''
                }`}
              >
                <div className="flex items-start">
                  <div className="flex-shrink-0 pt-1">
                    <input
                      type="checkbox"
                      checked={selectedNotifications.includes(notification.id)}
                      onChange={() => toggleSelection(notification.id)}
                      className="h-4 w-4 text-blue-600 focus:ring-blue-500 border-gray-300 rounded"
                    />
                  </div>
                  
                  <div className="ml-3 flex-1">
                    <div className="flex items-center justify-between">
                      <div className="flex items-center">
                        <div className={`h-2 w-2 rounded-full mr-2 ${getPriorityColor(notification.priority)}`}></div>
                        <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium ${getTypeColor(notification.type)}`}>
                          {getTypeLabel(notification.type)}
                        </span>
                      </div>
                      <span className="text-sm text-gray-500">
                        {new Date(notification.date).toLocaleDateString()}
                      </span>
                    </div>
                    
                    <h3 className="mt-1 text-base font-medium">{notification.title}</h3>
                    <p className="mt-1 text-sm text-gray-600">{notification.message}</p>
                    
                    {notification.action && (
                      <div className="mt-2">
                        <a 
                          href={notification.action.link} 
                          className="inline-flex items-center px-3 py-1.5 border border-transparent text-xs font-medium rounded-md text-blue-700 bg-blue-100 hover:bg-blue-200 focus:outline-none"
                        >
                          {notification.action.label}
                        </a>
                      </div>
                    )}
                  </div>
                </div>
              </div>
            ))}
          </div>
        ) : (
          <div className="p-8 text-center">
            <div className="inline-flex items-center justify-center h-16 w-16 rounded-full bg-gray-100 mb-4">
              <Bell className="h-8 w-8 text-gray-400" />
            </div>
            <h3 className="text-lg font-medium text-gray-900 mb-1">No notifications found</h3>
            <p className="text-gray-500">
              {filter === 'all' 
                ? "You don't have any notifications yet" 
                : `No ${filter} notifications found`}
            </p>
          </div>
        )}
      </div>
    </div>
  );
};

export default Notifications;