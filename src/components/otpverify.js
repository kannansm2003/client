import React, { useState, useEffect } from 'react';
import axios from 'axios';
//import { sha512 } from 'crypto-hash';
import CryptoJS from 'crypto-js';
import html2canvas from 'html2canvas';
import jsPDF from 'jspdf';
import { useNavigate } from 'react-router-dom';
//const crypto = require('crypto');

function App() {
    const [email, setEmail1] = useState('');
    const [userDetails, setUserDetails] = useState(null);
    const [hashedDetails, setHashedDetails] = useState('');
    const [otp, setOtp] = useState('');
    const [message, setMessage] = useState('');
    const navigate = useNavigate();
    useEffect(() => {
        // Fetch user details when the component mounts
        if (email) {
            axios.get(`https://172.16.23.161:3000/get-user-details?email=${email}`)
                .then(response => {
                    setUserDetails(response.data);
                })
                .catch(error => {
                    console.error(error);
                    setMessage('Error fetching user details');
                });
        }
    }, [email]);
    const generateCertificate = () => {
    const certificateElement = document.getElementById('certificate');
  
    if (!certificateElement) {
      console.error('Certificate element not found.');
      return;
    }
  
    // Ensure the element is visible
    certificateElement.style.display = 'block';
  
    html2canvas(certificateElement, { scale: 2 }).then(canvas => {
      try {
        const imgData = canvas.toDataURL('image/png');
        const pdf = new jsPDF('portrait', 'px', 'a4');
        pdf.addImage(imgData, 'PNG', 0, 0);

        // Convert the PDF to a Base64 string
        const pdfBase64 = pdf.output('datauristring');

        // Protect the PDF with a password (hashedDetails as the password)
        const hashedDetails = getHashedUserDetails(); // You should define this function to get the hashed details.
        pdf.setEncryption(hashedDetails, hashedDetails, [1, 2, 3], 'AES-256');

        // Store the password-protected PDF in local storage
        localStorage.setItem('certificatePDF', pdf.output('datauristring'));
  
        // Provide a link or button to retrieve or download the PDF
        alert('PDF has been stored in local storage and protected with the hashed user details. You can retrieve or download it later.');
  
      } catch (error) {
        console.error('Error generating PDF:', error);
        // Handle the error as needed
      } finally {
        // Restore the element's visibility to its original state
        certificateElement.style.display = 'none';
      }
    });
};

// Define a function to get the hashed user details (similar to hashUserDetails)
const getHashedUserDetails = () => {
    if (userDetails) {
        const { pan_num, aadhar, mobile } = userDetails;
        const detailsToHash = `${pan_num}${aadhar}${mobile}`;
        return CryptoJS.SHA512(detailsToHash).toString();
    } else {
        return '';
    }
};

      
      
      
    
    const hashUserDetails = () => {
        if (userDetails) {
            const { pan_num, aadhar, mobile } = userDetails;

            // Concatenate user details into a single string
            const detailsToHash = `${pan_num}${aadhar}${mobile}`;

            // Use crypto-js to compute the SHA-512 hash
            const hashedDetails = CryptoJS.SHA512(detailsToHash).toString();

            setHashedDetails(hashedDetails);
        } else {
            setMessage('User details not available');
        }
    };
    

    const generateOTP = () => {
        axios.post('https://172.16.23.161:3000/generate-otp', { 
          email: email 
        }).then(response => {
            setMessage(response.data.message);
        })
        .catch(error => {
            console.error(error);
            setMessage('Error generating OTP');
        });
    };
    const logout = () => {
        // Clear the user's session (e.g., remove tokens or user data from local storage)
    
        // Redirect the user to the login page
        navigate('/'); // Use the navigate function to change the route
    };
    const verifyOTP = () => {
        axios.post('https://172.16.23.161:3000/verify-otp', { email, otp })
            .then(response => {
                setMessage(response.data.message);
            })
            .catch(error => {
                console.error(error);
                setMessage('Error verifying OTP');
            });
    };

    return (
        <div className="App">
            <header className="App-header">
                <h1>Welcome to My React App</h1>
                <p>Enjoy your React journey!</p>
                <form>
                    <label>Enter your email: </label>
                    <input
                        type="email"
                        value={email}
                        onChange={(e) => setEmail1(e.target.value)}
                    />
                    <button type="button" onClick={generateOTP}>Generate OTP</button>
                </form>
                <form>
                    <label>Enter the OTP: </label>
                    <input
                        type="text"
                        value={otp}
                        onChange={(e) => setOtp(e.target.value)}
                    />
                    <button type="button" onClick={verifyOTP}>Verify OTP</button>
                </form>
                <button type="button" onClick={hashUserDetails}>Hash Details</button>
                <button type="button" onClick={generateCertificate}>Generate Certificate</button>
        <p>User Details: {JSON.stringify(userDetails)}</p>
        <p>Hashed User Details: {hashedDetails}</p>
        <button type="button" onClick={logout}>Logout</button>
        <p>{message}</p>
      </header>
      <div id="certificate" style={{ display: 'none' }}>
        <h1>Certificate of Achievement</h1>
        <p>Aadhar: {userDetails?.aadhar}</p>
        <p>PAN Number: {userDetails?.pan_num}</p>
        <p>Mobile Number: {userDetails?.mobile}</p>
      </div>
        </div>
    );
}

export default App;
