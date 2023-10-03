import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import {Stadion} from './Stadion';
import {Weather} from './Weather'
import { BrowserRouter as Router, Route, Routes } from "react-router-dom";

const root = ReactDOM.createRoot(document.getElementById("root"));

root.render(
  <Router>
    <Routes>
      <Route path="/" element={<App />} />
      <Route path="/tostadion" element={<Stadion />} />
      <Route path="/toweather" element={<Weather />} />
    </Routes>
  </Router>
);
