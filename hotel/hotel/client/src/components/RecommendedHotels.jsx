import React, { useEffect, useState } from 'react'
import Hotelcard from './hotelcard'
import Title from './title'
import { useAppContext } from '../context/AppContext'

const RecommendedHotels = () => {
  const { rooms, searchCities } = useAppContext()

  // ✅ Correct useState
  const [recommended, setRecommended] = useState([])

  // ✅ Filter hotels based on searched cities
  useEffect(() => {
    if (!rooms || rooms.length === 0) return

    const filtered = rooms.filter(room =>
      searchCities.includes(room.hotel.city)
    )

    setRecommended(filtered)
  }, [rooms, searchCities])

  // ✅ Guard render
  if (recommended.length === 0) return null

  return (
    <div className="min-h-screen bg-black p-0 mt-8">
      <Title
        title="Recommended Hotels"
        subtitle="Perfectly located, thoughtfully designed, and made for travelers like you."
      />

      <div className='flex flex-col items-center px-4 md:px-16 lg:px-20 bg-black py-10'>
        <div className='flex flex-wrap items-center justify-center gap-6'>
          {recommended.slice(0, 4).map((room, index) => (
            <Hotelcard
              key={room._id}
              room={room}
              index={index}
            />
          ))}
        </div>
      </div>
    </div>
  )
}

export default RecommendedHotels
