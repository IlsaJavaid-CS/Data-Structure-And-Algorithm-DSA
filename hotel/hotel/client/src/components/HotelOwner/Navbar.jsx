import React from 'react'
import {UserButton} from '@clerk/clerk-react'
import { Link } from 'react-router-dom'
import { assets } from '../../assets/assets'

const Navbar = () => {
  return (
    <div className='flex items-center justify-between h-18 px-2 md:px-8  border-b border-gray-500 py-3 bg-white/70 transition-all duration-300'>
    <Link to='/'>
    <img src={assets.log} alt="logo" className='h-25 invert opacity-80' /></Link>
    <UserButton/>
    </div>
  )
}

export default Navbar
