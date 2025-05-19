import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Dashboard from './pages/Dashboard';
import Clients from './pages/Clients';
import ClientProfile from './pages/ClientProfile';
import Notifications from './pages/Notifications';
import Campaigns from './pages/Campaigns';
import Layout from './components/Layout';
import './App.css';

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Layout />}>
          <Route index element={<Dashboard />} />
          <Route path="clients" element={<Clients />} />
          <Route path="client/:id" element={<ClientProfile />} />
          <Route path="notifications" element={<Notifications />} />
          <Route path="campaigns" element={<Campaigns />} />
        </Route>
      </Routes>
    </Router>
  );
}

export default App;