import React from 'react'
import { assets } from '../../assets/assets'
import { NavLink } from 'react-router-dom'

const SideBar = () => {
    const SideBarLinks = [
        {name: "Dashboard" ,path: "/owner" , icon: assets.dashboardIcon },
        {name: "Add Room" ,path: "/owner/add-room" , icon: assets.addIcon },
        {name: "List Room" ,path: "/owner/list-room" , icon: assets.listIcon },
    ]
  return (
    <div className='md-w-40 w-44 border-r h-full text-base border-gray-400 pt-5 flex flex-col transition-all duration-300'>
      {SideBarLinks.map((item , index)=>(
           <NavLink to={item.path} key={index} end='owner' className={({isActive})=>`flex items-center py-3 px-3 md:px-6 gap-3 ${isActive ? "border-r-4 md:border-r-[6px] bg-gray-400/20 border-gray-50 text-blue-500" : "hover:bg-gray-600/40 border border-gray-500 text-white" }`} >
           <img src={item.icon} alt={item.name} className='min-h-6 min-w-6'/>
           <p className='md:block hidden text-center'>{item.name}</p>
           
           </NavLink>
      ))}
    </div>
  )
}

export default SideBar
