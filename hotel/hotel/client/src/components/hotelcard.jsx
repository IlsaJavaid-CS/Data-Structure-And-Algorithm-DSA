import React from 'react'
import { Link } from 'react-router-dom'
import { assets } from '../assets/assets'

const Hotelcard = ({ room, index }) => {
  return (
    <Link 
      to={'/rooms/' + room._id} 
      onClick={() => scrollTo(0, 0)} 
      key={room._id}
      className="block bg-gray-600/20 hover:bg-gray-600/30 transition-colors rounded-xl overflow-hidden shadow-lg"
    >
      {/* Image container with smoky grey */}
      <div className="flex flex-wrap justify-center items-center  p-3 relative">
        <img 
          src={room.images[0]} 
          alt="room" 
          className="w-56 h-32 object-cover rounded-lg shadow-md"
        />
        {index % 2 === 0 && (
          <p className="px-3 py-1 absolute top-3 left-3 text-xs bg-black/70 text-white font-medium rounded-full shadow">
            Best Seller
          </p>
        )}
      </div>

      {/* Content */}
      <div className="p-3 text-white">
        {/* Title + Rating */}
        <div className="flex items-center justify-between mb-2">
          <p className="font-playfair text-lg font-semibold">
            {room.hotel.name}
          </p>
          <div className="flex items-center gap-1 text-sm">
            <img src={assets.starIconFilled} alt="star" className="w-4 h-4" />
            <span>4.5</span>
          </div>
        </div>

        {/* Location */}
        <div className="flex items-center gap-2 text-gray-300 text-sm mb-4">
          <img src={assets.locationIcon} alt="location" className="w-4 h-4" />
          <span>{room.hotel.address}</span>
        </div>

        {/* Price + Button */}
        <div className="flex items-center justify-between mt-2">
          <p>
            <span className="text-xl font-bold text-white">${room.pricePerNight}</span>
            <span className="text-gray-400 text-sm"> /night</span>
          </p>
          <button className="px-4 py-2 text-sm font-medium bg-gradient-to-r from-gray-600 to-balck hover:bg-gray-700 rounded-lg shadow-md transition-all">
            Book Now
          </button>
        </div>
      </div>
    </Link>
  )
}

export default Hotelcard
