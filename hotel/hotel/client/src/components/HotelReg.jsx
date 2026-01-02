import React, { useState } from 'react'
import { assets, cities } from '../assets/assets'
import { useAppContext } from '../context/AppContext'
import { data } from 'react-router-dom';
import toast from 'react-hot-toast';

const HotelReg = () => {

    const {setShowHotelReg , axios , getToken,setIsOwner } = useAppContext();

    const [name , setName] = useState("")
    const [address, setAdddress] = useState("")
    const [contact , setContact] = useState("")
    const [city , setCity] = useState("")
    const onSubmitHandler = async (event) =>{
        try {
            event.preventDefault();
          const { data } = await axios.post('http://localhost:3000/api/hotels',  {name, contact, address, city}
         , {headers: {Authorization: `Bearer ${await getToken()}`}}
        )
            if(data.success){
                toast.success(data.message)
                setIsOwner(true)
                setShowHotelReg(false);
            }
            else{
                toast.error(data.message)
            }
        } catch (error) {
              toast.error(error.message)
            
        }
    }
  return (

    <div onClick={()=>setShowHotelReg(false)} className='fixed top-0 bottom-0 left-0 right-0 z-100 flex items-center justify-center bg-gray-900/40'>
        <form onSubmit={onSubmitHandler} onClick={(e)=>e.stopPropagation()} className='flex bg-black/90 rounded-xl max-w-4xl max-md:mx-2 border-2 border-white'>
            <img src={assets.regii} alt="reg-img" className='w-1/2 rounded-xl hidden md:block'/>
            <div className='relative flex flex-col items-center md:w-1/2 p-8 md:p-10'>
            <img src={assets.closeIcon} alt="close-icon" className='absolute top-4 right-4 h-4 w-4 cursor-pointer' onClick={()=> setShowHotelReg(false)} />
            <p className='text-2xl font-semibold mt-6 font-playfair'>
                    Register Here Please!
            </p>
            {/* hotel name */}
            <div className='w-full mt-4'>
                    <label htmlFor="Contact" className='font-medium text-gray-100'>Hotel</label>
                    <input id='name' onChange={(e)=>setName(e.target.value)} type="text" placeholder='Type here Please' className='border border-gray-200 rounded-full w-full px-3 py-2.5 mt-1 outline-gray-900 font-light' required/>
            </div>

        {/* Contact  */}
            <div className='w-full mt-4'>
                    <label htmlFor="contact" className='font-medium text-gray-100'>Contact</label>
                    <input id="Contact" onChange={(e)=>setContact(e.target.value)}  type="text" placeholder='Type here Please' className='border border-gray-200 rounded-full w-full px-3 py-2.5 mt-1 outline-gray-900 font-light' required/>
            </div>
                   {/* address  */}
                    <div className='w-full mt-4'>
                    <label htmlFor="address" className='font-medium text-gray-100'>Address</label>
                    <input id="address"  onChange={(e)=>setAdddress(e.target.value)}  type="text" placeholder='Type here Please' className='border border-gray-200 rounded-full w-full px-3 py-2.5 mt-1 outline-gray-900 font-light' required/>
            </div>

            {/* select city dropdown */}
            <div className='w-full mt-4 max-w-60 mr-auto'>
                <label htmlFor="city" className='font-medium text-gray-100'>City</label>
                <select id="city" onChange={(e)=>setCity(e.target.value)} value={city}  className='border border-white rounded-xl w-full px-3 py-2.5 mt-1 outline-gray-900 font-dark' required>
                    <option value="">Select City here</option>
                    {cities.map((city)=>(
                        <option className='bg-black' key={city} value={city}>{city}</option>
                    ))}
                </select>
            </div>
            <button type='submit' className='bg-gray-900 hover:bg-gray-700 transition-all text-white mr-auto px-6 py-2 rounded cursor-pointer mt-6 border-2 border-white'>
                Reserve
            </button>
            </div>

            
        </form>
      
    </div>
  )
}

export default HotelReg;

