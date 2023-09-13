import React from 'react';

const Footer = () => {
  return (
    <footer className="bg-blue-500 p-6 mt-8">
      <div className="container mx-auto text-center text-white">
        <p className="text-sm">&copy; {new Date().getFullYear()} The University Portal. All rights reserved.</p>
      </div>
    </footer>
  );
};

export default Footer;
