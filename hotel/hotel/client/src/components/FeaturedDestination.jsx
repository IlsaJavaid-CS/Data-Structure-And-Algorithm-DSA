import React from 'react'
import Hotelcard from './hotelcard'
import Title from './title'
import { useNavigate } from 'react-router-dom'
import { useAppContext } from '../context/AppContext'


const FeaturedDestination = () => {
  const {rooms, navigate} = useAppContext();

 
  return rooms.length >0 && (
    
<div className="min-h-screen bg-black p-0 mt-8">
  <Title title="Your Escape Awaits" subtitle="Perfectly located, thoughtfully designed, and made for travelers like you Where modern design meets unforgettable comfort,Experience timeless elegance, comfort, and world-class hospitality "/>
    <div className='flex flex-col items-center px-4 md:px-16 lg:px-20 bg-black py-10'>
    <div className='flex flex-wrap items-center justify-content gap-6 '>
        {rooms.slice(0,4).map((room , index)=>(<Hotelcard key ={room._id} room={room} index={index}/>
    ))}
    </div>
    <button onClick={()=>{navigate('/rooms') , scrollTo(0,0)}} className='my-10 px-4 py-2 text-sm font-medium bg-gradient-to-r from-gray-600 to-balck hover:bg-gray-700 rounded-lg shadow-md transition-all"cursor-pointer'>
      View All Destinations
    </button>
    </div>
     </div>
  )
}

export default FeaturedDestination