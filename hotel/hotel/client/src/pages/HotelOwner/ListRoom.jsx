import React, { useEffect, useState } from 'react'
// import { roomsDummyData } from '../../assets/assets'
import Title from '../../components/title'
import { useAppContext } from '../../context/AppContext'
import toast from 'react-hot-toast'

const ListRoom = () => {
  const [rooms , setRooms] = useState([])
  const {axios, getToken, user } = useAppContext()
  //Fetch room for the hotel owner
  const fetchRooms = async ()=>{
    try {
      const {data} = await axios.get('/api/rooms/owner' , {headers: {Authorization: `Bearer ${await getToken()}`}})
      if(data.success){
        setRooms(data.rooms)
      }
      else{
        toast.error(data.message)
      }
    } catch (error) {
        toast.error(error.message)
    }
  }

  //Toggle room availability

  const toggleAvailability = async (roomId)=>{
    const {data} = await axios.post('/api/rooms/toggle-availability' , {roomId},{headers: {Authorization: `Bearer ${await getToken()}`}} )
    if (data.success){
      toast.success(data.message)
      fetchRooms()
    }
    else{
      toast.error(data.message)
    }
  }
  useEffect(()=>{
      if(user){
        fetchRooms()
      }
  }, [user])
  return (
    <div>
      <Title align="left"  title='Dear Owner! Kindly List the Room' subtitle='Add images to showcase your room effectively.
Well-presented photos increase visibility and booking chances....'/>
<p className='text-white mt-2'>All Rooms</p>
<div className='w-full max-w-3xl text-left border border-gray-900 rounded-lg max-h-80 overflow-y-scroll'>
        <table className='w-full'>
                <thead className='bg-gray-900 '>
                    <tr>
                        <th className='py-3 px-4 text-white font-medium'>Name</th>
                        <th className='py-3 px-4 text-white font-medium max-sm:hidden'>Facility </th>
                        <th className='py-3 px-4 text-white font-medium'>Price per Night</th>
                        <th className='py-3 px-4 text-white font-medium text-center'>Actions </th>
                    </tr>
                </thead>
                <tbody className='text-sm'>
                                {rooms.map((item, index)=>(
                                    <tr key={index}>
                                        <td className='py-3 px-4 text-gray-200 border-t border-gray-300 '>
                                            {item.roomType}
                                        </td>
                                       
                                        <td className='py-3 px-4 text-gray-200 border-t border-gray-300 text-center max-sm:hidden'>
                                            ${item.amenities.join(', ')}
                                        </td >
                                        <td className='py-3 px-4 text-gray-200 border-t border-gray-300'>
                                            ${item.pricePerNight}
                                        </td >
                                          <td className='py-3 px-4 border-t border-gray-300 text-center text-sm text-red-500'>
                                            <label className='relative inline-flex items-center cursor-pointer text-white gap=3'>
                                              <input onChange={()=> toggleAvailability(item._id)} type="checkbox"  className='sr-only peer' checked={item.isAvailable} />
                                              <div className='w-12 h-7 bg-gray-800 rounded-full peer peer-checked:bg-purple-500 transition-colors duration-200'>
                                                <span className='dot absolute left-1 top-1 w-5 h-5 bg-white rounded-full transition-transform duration-200 ease-in-out peer-checked:translate-x-5'>

                                                </span>

                                              </div>
                                            </label>
                                        </td >
                                      

                                    </tr>
                                ))}
                </tbody>
        </table>
    </div>
    </div>
  )
}

export default ListRoom
