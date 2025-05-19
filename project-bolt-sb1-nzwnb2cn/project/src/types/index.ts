export interface User {
  id: string;
  name: string;
  role: string;
  avatar: string;
}

export interface Client {
  id: string;
  firstName: string;
  lastName: string;
  email: string;
  phone: string;
  address: string;
  birthDate: string;
  profilePicture?: string;
  idCard?: string;
  status: 'prospect' | 'active' | 'dormant';
  lastContact?: string;
  riskScore: number;
  lifetimeValue: number;
  products: Product[];
  claims: Claim[];
  interactions: Interaction[];
}

export interface Product {
  id: string;
  name: string;
  type: 'auto' | 'home' | 'life' | 'health' | 'retirement';
  startDate: string;
  endDate: string;
  premium: number;
  status: 'active' | 'pending' | 'expired';
  details: {
    [key: string]: any;
  };
}

export interface Claim {
  id: string;
  productId: string;
  date: string;
  amount: number;
  status: 'pending' | 'approved' | 'rejected' | 'paid';
  description: string;
}

export interface Interaction {
  id: string;
  date: string;
  channel: 'email' | 'phone' | 'in-person' | 'web' | 'app';
  type: 'inquiry' | 'service' | 'claim' | 'payment' | 'renewal';
  summary: string;
  agentId: string;
}

export interface Recommendation {
  id: string;
  productType: 'auto' | 'home' | 'life' | 'health' | 'retirement';
  name: string;
  description: string;
  premium: number;
  score: number;
  reasoning: string[];
  potentialSavings?: number;
  additionalCoverage?: string[];
}

export interface Notification {
  id: string;
  clientId: string;
  type: 'renewal' | 'claim' | 'payment' | 'opportunity' | 'alert';
  title: string;
  message: string;
  date: string;
  read: boolean;
  priority: 'low' | 'medium' | 'high';
  action?: {
    type: string;
    label: string;
    link: string;
  };
}

export interface Campaign {
  id: string;
  name: string;
  status: 'draft' | 'active' | 'completed' | 'scheduled';
  startDate: string;
  endDate?: string;
  targetAudience: string;
  productType: 'auto' | 'home' | 'life' | 'health' | 'retirement' | 'multi';
  metrics: {
    sent: number;
    opened: number;
    clicked: number;
    converted: number;
  };
  message: string;
}

export interface OCRResult {
  fullName?: string;
  dateOfBirth?: string;
  idNumber?: string;
  expiryDate?: string;
  address?: string;
  confidence: number;
}