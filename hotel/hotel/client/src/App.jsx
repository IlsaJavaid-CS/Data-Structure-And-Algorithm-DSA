
import React from 'react'
import Navbar from './components/Navbar'
import { BrowserRouter, Routes, Route, Link, useLocation } from "react-router-dom";
import Home from './pages/home';
import Footer from './components/Footer';
import Allrooms from './pages/Allrooms';
import RoomDetails from './pages/RoomDetails';
import MyBookings from './pages/MyBookings';
import HotelReg from './components/HotelReg';
import Layout from './pages/HotelOwner/Layout';
import Dashboard from './pages/HotelOwner/Dashboard';
import AddRoom from './pages/HotelOwner/AddRoom';
import ListRoom from './pages/HotelOwner/ListRoom';
import {Toaster} from 'react-hot-toast';
import { useAppContext } from './context/AppContext.jsx';
// import {useLocation} from 'react-router-dom'
const App = () => {

  const location = useLocation();
  const isOwnerPath =location.pathname.includes("owner");
const {showHotelReg} = useAppContext();
  return (
    
    <div className="flex flex-col min-h-screen">
     <Toaster/>
      { !isOwnerPath && <Navbar/>}
     {showHotelReg && <HotelReg />}
      <div className="flex-grow">
      <Routes>
        <Route path='/' element={<Home/>}/>
        <Route path='/rooms' element={<Allrooms/>}/>
        <Route path='/rooms/:id' element={<RoomDetails/>}/>
        <Route path='/my-bookings' element={<MyBookings/>}/>
        <Route path='/my-bookings' element={<MyBookings/>}/>
        <Route path='/owner' element={<Layout/>}>
            <Route index element = {<Dashboard/>}/>
            <Route path='add-room' element = {<AddRoom/>}/>
            <Route path='list-room' element = {<ListRoom/>}/>

        </Route>
       
      </Routes>
      </div>
         {!isOwnerPath && <Footer />}
    </div>
  )
}

export default App 
