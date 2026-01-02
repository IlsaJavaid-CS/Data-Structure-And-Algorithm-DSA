import React, { useState } from 'react'
import { cities } from '../assets/assets'
import { useAppContext } from '../context/AppContext'

const Hero = () => {

  const { navigate, getToken, axios, setSearchedCities } = useAppContext()
  const [destination, setDestination] = useState("")

  const onSearch = async (e) => {
    e.preventDefault()

    // navigate to rooms page
    navigate(`/rooms?destination=${destination}`)

    try {
      // store recent searched city (only if logged in)
      const token = await getToken()
      if (token) {
        await axios.post(
          '/api/user/store-recent-search',
          { recentSearchedCity: destination },
          { headers: { Authorization: `Bearer ${token}` } }
        )
      }

      // update searched cities (max 3)
      setSearchedCities((prev) => {
        const updated = [...prev, destination]
        if (updated.length > 3) updated.shift()
        return updated
      })

    } catch (error) {
      console.error("Search error:", error)
    }
  }

  return (
    <div className="relative h-screen overflow-x-hidden">

      {/* Background */}
      <div className="absolute inset-0">
        <img
          src="/gray.png"
          alt="background"
          className="w-full h-full object-cover"
        />
        <div className="absolute inset-0 bg-black/50"></div>
      </div>

      {/* Content */}
      <div className="relative z-10 flex flex-col justify-center px-6 md:px-16 lg:px-24 xl:px-32 text-white h-full">

        <p className="bg-[#6B7280]/50 px-3.5 py-1 rounded-full mt-20 w-fit">
          The Ultimate Hotel Experience
        </p>

        <h1 className="font-Outfit text-2xl md:text-[56px] md:leading-[56px] font-extrabold max-w-xl mt-5">
          Redefining relaxation and sophistication.
        </h1>

        <p className="max-w-xl mt-3 text-sm md:text-base">
          GreyHotel blends modern elegance with world-class comfort,
          offering an unforgettable atmosphere.
        </p>

        {/* Search Form */}
        <form
          onSubmit={onSearch}
          className="bg-gray-500/60 rounded-lg px-5 py-3 flex flex-col md:flex-row gap-4 mt-6 w-fit"
        >

          {/* Destination */}
          <div>
            <label className="text-sm">Destination</label>
            <input
              list="destinations"
              value={destination}
              onChange={(e) => setDestination(e.target.value)}
              className="block rounded border border-white px-3 py-1.5 mt-1 text-sm text-black outline-none"
              placeholder="Type city"
              required
            />
            <datalist id="destinations">
              {cities.map((city, index) => (
                <option key={index} value={city} />
              ))}
            </datalist>
          </div>

          {/* Check In */}
          <div>
            <label className="text-sm">Check In</label>
            <input
              type="date"
              className="block rounded border border-white px-3 py-1.5 mt-1 text-sm text-black outline-none"
            />
          </div>

          {/* Check Out */}
          <div>
            <label className="text-sm">Check Out</label>
            <input
              type="date"
              className="block rounded border border-white px-3 py-1.5 mt-1 text-sm text-black outline-none"
            />
          </div>

          {/* Guests */}
          <div>
            <label className="text-sm">Guests</label>
            <input
              type="number"
              min={1}
              max={4}
              className="block rounded border border-white px-3 py-1.5 mt-1 text-sm text-black outline-none w-20"
              placeholder="1"
            />
          </div>

          {/* Search Button */}
          <button
            type="submit"
            className="flex items-center justify-center gap-1 bg-black px-4 py-2 rounded text-white mt-auto"
          >
            Search
          </button>

        </form>
      </div>
    </div>
  )
}

export default Hero
