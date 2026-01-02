// import React, { useMemo, useState } from 'react'
// import { assets, facilityIcons } from '../assets/assets'
// import { useAppContext } from '../context/AppContext'
// import { useNavigate, useSearchParams } from 'react-router-dom'

// // Checkbox component
// const CheckBox = ({ label, selected = false, onChange = () => {} }) => {
//   return (
//     <label className='flex gap-3 items-center cursor-pointer mt-2 text-sm text-white'>
//       <input
//         type="checkbox"
//         checked={selected}
//         onChange={(e) => onChange(e.target.checked, label)}
//       />
//       <span className='select-none'>{label}</span>
//     </label>
//   )
// }

// // Radio button component
// const RadioButton = ({ label, selected = false, onChange = () => {} }) => {
//   return (
//     <label className='flex gap-3 items-center cursor-pointer mt-2 text-sm text-white'>
//       <input
//         type="radio"
//         name='sortOption'
//         checked={selected}
//         onChange={() => onChange(label)}
//       />
//       <span className='select-none'>{label}</span>
//     </label>
//   )
// }

// const Allrooms = () => {
//   const [searchParams, setSearchParams] = useSearchParams() // ✅ fixed declaration
//   const { rooms, navigate, currency } = useAppContext()

//   const [openFilters, setOpenFilters] = useState(false)
//   const [selectedFilters, setSelectedFilters] = useState({
//     roomTypes: [],
//     priceRanges: [],
//   })
//   const [selectedSort, setSelectedSort] = useState('')

//   const roomTypes = ["Single Bed", "Double Bed", "Luxury Room", "Family Suite"]
//   const priceRanges = ["0-500", "500-1000", "1000-2000", "2000-3000"]
//   const sortOptions = ["Price Low to High", "Price High to Low", "Newest First"]

//   // Handle filter changes
//   const handleFilterChange = (checked, value, type) => {
//     setSelectedFilters((prevFilters) => {
//       const updated = { ...prevFilters }
//       if (checked) {
//         updated[type].push(value)
//       } else {
//         updated[type] = updated[type].filter(item => item !== value)
//       }
//       return updated
//     })
//   }

//   // Handle sort change
//   const handleSortChange = (option) => setSelectedSort(option)

//   // Filter matching functions
//   const matchesRoomType = (room) =>
//     selectedFilters.roomTypes.length === 0 || selectedFilters.roomTypes.includes(room.roomType)

//   const matchesPriceRange = (room) =>
//     selectedFilters.priceRanges.length === 0 || selectedFilters.priceRanges.some(range => {
//       const [min, max] = range.split('-').map(Number)
//       return room.pricePerNight >= min && room.pricePerNight <= max
//     })

//   const filterDestination = (room) => {
//     const Destination = searchParams.get('destination')
//     if (!Destination) return true
//     return room.hotel.city.toLowerCase().includes(Destination.toLowerCase())
//   }

//   // Sort function
//   const sortRooms = (a, b) => {
//     if (selectedSort === 'Price Low to High') return a.pricePerNight - b.pricePerNight
//     if (selectedSort === 'Price High to Low') return b.pricePerNight - a.pricePerNight
//     if (selectedSort === 'Newest First') return new Date(b.createdAt) - new Date(a.createdAt)
//     return 0
//   }

//   // Filter and sort rooms using useMemo
//   const filteredRooms = useMemo(() => {
//     return rooms
//       .filter(room => matchesRoomType(room) && matchesPriceRange(room) && filterDestination(room))
//       .sort(sortRooms)
//   }, [rooms, selectedFilters, selectedSort, searchParams])

//   // Clear all filters
//   const clearFilters = () => {
//     setSelectedFilters({ roomTypes: [], priceRanges: [] })
//     setSelectedSort('')
//     setSearchParams({})
//   }

//   return (
//     <div className='font-playfair flex flex-col-reverse lg:flex-row justify-between mt-25 px-6 md:px-16 lg:px-24'>
      
//       {/* Rooms List */}
//       <div className='flex flex-col max-w-4xl'>
//         <h1 className='text-4xl md:text-[40px] text-white'>Hotel Rooms</h1>
//         <p className='text-sm md:text-base text-gray mt-2'>
//           Take advantage of our limited-time offers and special packages to enhance your stay.
//         </p>

//         {filteredRooms.map(room => (
//           <div key={room._id} className='flex flex-col md:flex-row items-start py-8 gap-6 border-b border-gray-200 last:pb-30 last:border-0'>
//             <img
//               onClick={() => { navigate(`/rooms/${room._id}`); scrollTo(0, 0) }}
//               src={room.images[0]}
//               alt="hotel img"
//               title='View Room Details'
//               className='max-h-50 md:w-1/2.5 rounded-xl shadow-lg object-cover cursor-pointer mt-6'
//             />
//             <div className='md:w-1/3 flex flex-col gap-2'>
//               <p className='text-white'>{room.hotel.city}</p>
//               <p
//                 onClick={() => { navigate(`/rooms/${room._id}`); scrollTo(0, 0) }}
//                 className='text-white text-2xl cursor-pointer'
//               >
//                 {room.hotel.name}
//               </p>
//               <div className='flex items-center text-white mt-2 gap-1 text-sm'>
//                 <img src={assets.locationIcon} alt="location" />
//                 <span>{room.hotel.address}</span>
//               </div>
//               {/* Amenities */}
//               <div className='flex flex-wrap items-center mt-3 mb-4 gap-2'>
//                 {room.amenities.map((item, index) => (
//                   <div key={index} className='flex items-center gap-2 px-2 py-2 rounded-lg bg-gray-400/20'>
//                     <img src={facilityIcons[item]} alt={item} className='w-5 h-5' />
//                     <p className='text-xs'>{item}</p>
//                   </div>
//                 ))}
//               </div>
//               <p className='text-xl text-white'>${room.pricePerNight} /night</p>
//             </div>
//           </div>
//         ))}
//       </div>

//       {/* Filters Sidebar */}
//       <div className='bg-black w-70 border border-gray-200 text-white min-lg:mb-250 pb-4 max-lg:mb-8 min-lg:mt-16'>
//         <div className='flex items-center justify-between px-5 py-2.5 lg:border-b border-gray-200'>
//           <p className='text-base font-medium'>Find Yours</p>
//           <div className='text-xs cursor-pointer'>
//             <span onClick={() => setOpenFilters(!openFilters)} className='lg:hidden'>
//               {openFilters ? "Hide" : "Show"}
//             </span>
//             <span className='hidden lg:block' onClick={clearFilters}>Clear</span>
//           </div>
//         </div>

//         <div className={`${openFilters ? 'h-auto' : 'h-0 lg:h-auto'} overflow-hidden transition-all duration-700`}>
//           <div className='px-5 pt-5'>
//             <p className='font-medium pb-2'>Popular Filters</p>
//             {roomTypes.map((room, index) => (
//               <CheckBox
//                 key={index}
//                 label={room}
//                 selected={selectedFilters.roomTypes.includes(room)}
//                 onChange={(checked) => handleFilterChange(checked, room, 'roomTypes')}
//               />
//             ))}
//           </div>
//           <div className='px-5 pt-5'>
//             <p className='font-medium pb-2'>Price Range</p>
//             {priceRanges.map((range, index) => (
//               <CheckBox
//                 key={index}
//                 label={`${currency} ${range}`}
//                 selected={selectedFilters.priceRanges.includes(range)}
//                 onChange={(checked) => handleFilterChange(checked, range, 'priceRanges')}
//               />
//             ))}
//           </div>
//           <div className='px-5 pt-5'>
//             <p className='font-medium pb-2'>Sort by</p>
//             {sortOptions.map((option, index) => (
//               <RadioButton
//                 key={index}
//                 label={option}
//                 selected={selectedSort === option}
//                 onChange={handleSortChange}
//               />
//             ))}
//           </div>
//         </div>
//       </div>
//     </div>
//   )
// }

// export default Allrooms



import React, { useMemo, useState } from 'react'
import { assets, facilityIcons } from '../assets/assets'
import { useAppContext } from '../context/AppContext'
import { useNavigate, useSearchParams } from 'react-router-dom'

// Checkbox component
const CheckBox = ({ label, selected = false, onChange = () => {} }) => (
  <label className='flex gap-3 items-center cursor-pointer mt-2 text-sm text-white'>
    <input
      type="checkbox"
      checked={selected}
      onChange={(e) => onChange(e.target.checked, label)}
    />
    <span className='select-none'>{label}</span>
  </label>
)

// Radio button component
const RadioButton = ({ label, selected = false, onChange = () => {} }) => (
  <label className='flex gap-3 items-center cursor-pointer mt-2 text-sm text-white'>
    <input
      type="radio"
      name='sortOption'
      checked={selected}
      onChange={() => onChange(label)}
    />
    <span className='select-none'>{label}</span>
  </label>
)

const Allrooms = () => {
  const [searchParams, setSearchParams] = useSearchParams()
  const { rooms, currency } = useAppContext()
  const navigate = useNavigate()   // useNavigate instead of context

  const [openFilters, setOpenFilters] = useState(false)
  const [selectedFilters, setSelectedFilters] = useState({
    roomTypes: [],
    priceRanges: [],
  })
  const [selectedSort, setSelectedSort] = useState('')

  const roomTypes = ["Single Bed", "Double Bed", "Luxury Room", "Family Suite"]
  const priceRanges = ["0-500", "500-1000", "1000-2000", "2000-3000"]
  const sortOptions = ["Price Low to High", "Price High to Low", "Newest First"]

  //  Handle filter changes
  const handleFilterChange = (checked, value, type) => {
    setSelectedFilters((prevFilters) => {
      const updated = { ...prevFilters }
      if (checked) {
        updated[type].push(value)
      } else {
        updated[type] = updated[type].filter(item => item !== value)
      }
      return updated
    })
  }

  // Sort function
  const sortRooms = (a, b) => {
    if (selectedSort === 'Price Low to High') return a.pricePerNight - b.pricePerNight
    if (selectedSort === 'Price High to Low') return b.pricePerNight - a.pricePerNight
    if (selectedSort === 'Newest First') {
      return new Date(b.createdAt || 0) - new Date(a.createdAt || 0)
    }
    return 0
  }

  //  Filter functions
  const matchesRoomType = (room) =>
    selectedFilters.roomTypes.length === 0 || selectedFilters.roomTypes.includes(room.roomType)

  const matchesPriceRange = (room) =>
    selectedFilters.priceRanges.length === 0 || selectedFilters.priceRanges.some(range => {
      const [min, max] = range.split('-').map(Number)
      return room.pricePerNight >= min && room.pricePerNight <= max
    })

  const filterDestination = (room) => {
    const Destination = searchParams.get('destination')
    if (!Destination) return true
    return room.hotel?.city?.toLowerCase().includes(Destination.toLowerCase())
  }

  // Filter and sort rooms
  const filteredRooms = useMemo(() => {
    return rooms
      .filter(room => matchesRoomType(room) && matchesPriceRange(room) && filterDestination(room))
      .sort(sortRooms)
  }, [rooms, selectedFilters, selectedSort, searchParams])

  // Clear filters
  const clearFilters = () => {
    setSelectedFilters({ roomTypes: [], priceRanges: [] })
    setSelectedSort('')
    setSearchParams({})
  }

  return (
    <div className='font-playfair flex flex-col-reverse lg:flex-row justify-between mt-24 px-6 md:px-16 lg:px-24'>
      
      {/* Rooms List */}
      <div className='flex flex-col max-w-4xl'>
        <h1 className='text-4xl md:text-[40px] text-white'>Hotel Rooms</h1>
        <p className='text-sm md:text-base text-gray mt-2'>
          Take advantage of our limited-time offers and special packages to enhance your stay.
        </p>

        {filteredRooms.map(room => (
          <div key={room._id} className='flex flex-col md:flex-row items-start py-8 gap-6 border-b border-gray-200 last:pb-8 last:border-0'>
            <img
              onClick={() => { navigate(`/rooms/${room._id}`); scrollTo(0, 0) }}
              src={room.images?.[0]}
              alt="hotel img"
              title='View Room Details'
              className='max-h-56 md:w-1/2 rounded-xl shadow-lg object-cover cursor-pointer mt-6'
            />
            <div className='md:w-1/3 flex flex-col gap-2'>
              <p className='text-white'>{room.hotel?.city}</p>
              <p
                onClick={() => { navigate(`/rooms/${room._id}`); scrollTo(0, 0) }}
                className='text-white text-2xl cursor-pointer'
              >
                {room.hotel?.name}
              </p>
              <div className='flex items-center text-white mt-2 gap-1 text-sm'>
                <img src={assets.locationIcon} alt="location" />
                <span>{room.hotel?.address}</span>
              </div>
              {/* Amenities */}
              <div className='flex flex-wrap items-center mt-3 mb-4 gap-2'>
                {room.amenities?.map((item, index) => (
                  <div key={index} className='flex items-center gap-2 px-2 py-2 rounded-lg bg-gray-400/20'>
                    {facilityIcons[item] && <img src={facilityIcons[item]} alt={item} className='w-5 h-5' />}
                    <p className='text-xs'>{item}</p>
                  </div>
                ))}
              </div>
              <p className='text-xl text-white'>${room.pricePerNight} /night</p>
            </div>
          </div>
        ))}
      </div>

      {/* Filters Sidebar */}
      <div className='bg-black w-72 border border-gray-200 text-white pb-4 max-lg:mb-8 lg:mt-16'>
        <div className='flex items-center justify-between px-5 py-2.5 lg:border-b border-gray-200'>
          <p className='text-base font-medium'>Find Yours</p>
          <div className='text-xs cursor-pointer'>
            <span onClick={() => setOpenFilters(!openFilters)} className='lg:hidden'>
              {openFilters ? "Hide" : "Show"}
            </span>
            <span className='hidden lg:block' onClick={clearFilters}>Clear</span>
          </div>
        </div>

        <div className={`${openFilters ? 'h-auto' : 'h-0 lg:h-auto'} overflow-hidden transition-all duration-700`}>
          <div className='px-5 pt-5'>
            <p className='font-medium pb-2'>Popular Filters</p>
            {roomTypes.map((room, index) => (
              <CheckBox
                key={index}
                label={room}
                selected={selectedFilters.roomTypes.includes(room)}
                onChange={(checked) => handleFilterChange(checked, room, 'roomTypes')}
              />
            ))}
          </div>
          <div className='px-5 pt-5'>
            <p className='font-medium pb-2'>Price Range</p>
            {priceRanges.map((range, index) => (
              <CheckBox
                key={index}
                label={`${currency} ${range}`}
                selected={selectedFilters.priceRanges.includes(range)}
                onChange={(checked) => handleFilterChange(checked, range, 'priceRanges')}
              />
            ))}
          </div>
          <div className='px-5 pt-5'>
            <p className='font-medium pb-2'>Sort by</p>
            {sortOptions.map((option, index) => (
              <RadioButton
                key={index}
                label={option}
                selected={selectedSort === option}
                onChange={setSelectedSort}
              />
            ))}
          </div>
        </div>
      </div>
    </div>
  )
}

export default Allrooms
