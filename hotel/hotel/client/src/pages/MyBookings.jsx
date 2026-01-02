import React, { useState } from 'react'
import Title from '../components/title'
import { assets, userBookingsDummyData } from '../assets/assets'
const MyBookings = () => {

  const [Bookings, setBookings] = useState(userBookingsDummyData)
  return (
    <div className='py-28 md:pb-35 md:pt-20 px-4 md:px-16 lg:px-24 xl:px-32'>

      <Title title='My Bookings' subtitle="Secure your perfect stay with just a few clicks. Book now and experience comfort, luxury, and unforgettable moments" align="left" />

      <div className='max-w-6xl mt-8 w-full text-white-500'>
        <div className='md:grid md:grid-cols-[3fr_2fr_1fr] w-full border-b border-white font-medium py-3'>
          <div className='w-1/3'>Hotels</div>
          <div className='w-1/3'>Date and timimgs</div>
          <div className='w-1/3'>Payments</div>
        </div>

        {Bookings.map((Bookings) => (
          <div key={Bookings._id} className='grid grid:cols-1 md:grid-cols-[3fr_2fr_1fr] w-full border-gray-300 py-5 first-border-t'>
            {/* hotel details column */}
            <div className='flex flex-col md:flex-row'>
              <img className='min-md:w-44 rounded shadow object-cover' src={Bookings.room.images[0]} alt="hotel-image" />
              <div className='flex flex-col gap-1.5 max-md:mt-3 min-md:ml-4'>
                <p className='font-playfair text-2xl'>{Bookings.hotel.name}
                  <span className='font-inner text-sm'>
                    ({Bookings.room.roomType})
                  </span>
                </p>
                <div className='flex items-center gap-1 text-sm text-white'>
                  <img src={assets.locationIcon} alt="location-iocn" />
                  <span>{Bookings.hotel.address}</span>
                </div>
                <div className='flex items-center gap-1 text-sm text-white'>
                  <img src={assets.guestsIcon} alt="guest-iocn" />
                  <span>{Bookings.guests}</span>
                </div>

                <p className='text-base'>
                  total: ${Bookings.totalPrice}
                </p>
              </div>
            </div>

            {/* date and timing div */}
            <div className='flex flex-row md:items-center md:gap-12 mt-3 gap-8'>
              <div className="flex flex-row items-center gap-12">
              <div  className="flex flex-col">
                <p>Check-In:</p>
                <p className='text-white text-sm ml'>
                  {new Date(Bookings.checkInDate).toDateString()}
                </p>
              </div>
               <div className="flex flex-col">
                <p>Check-Out:</p>
                <p className='text-white text-sm'>
                  {new Date(Bookings.checkOutDate).toDateString()}
                </p>
              </div>
            </div>
              </div>


            {/* payment status */}
            <div className='flex flex-col items-start justify-center pt-3'>
            <div className='flex items-center gap-2'>
              <div className={`h-3 w-3  rounded-full ${Bookings.isPaid ? "bg-green-500" : "bg-red-500" }`}></div>
                <p className={`text-sm  ${Bookings.isPaid ? "text-green-500" : "text-red-500"}`}>
                  {Bookings.isPaid ? "Paid" : "Unpaid"}
                  </p>
              </div>
              {!Bookings.isPaid && (
                <button className='px-4 py-1.5 mt-2 ml-2 text-xs border border-white rounded-full hover:bg-gray-300/30 transition-all cursor-pointer'>Pay Now</button>
              )}
       
            </div>
          </div>
        ))}
      </div>
    </div>
  )
}

export default MyBookings