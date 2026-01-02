import React, { useEffect, useState } from 'react'
import Title from '../../components/title'
import { assets } from '../../assets/assets'
import { useAppContext } from '../../context/AppContext'

const Dashboard = () => {
  const { currency, user, getToken, toast, axios } = useAppContext()

  const [dashboard, setDashboard] = useState({
    bookings: [],
    totalBookings: 0,
    totalRevenue: 0
  })

  const fetchDashboardData = async () => {
    try {
      const { data } = await axios.get(
        '/api/bookings/hotel',
        {
          headers: {
            Authorization: `Bearer ${await getToken()}`
          }
        }
      )

      if (data.success) {
        setDashboard(data.dashboardData)
      } else {
        toast.error(data.message)
      }
    } catch (error) {
      toast.error(error.message)
    }
  }

  useEffect(() => {
    if (user) {
      fetchDashboardData()
    }
  }, [user])

  return (
    <div>
      <Title
        align="left"
        font="outfit"
        title="Welcome to your Owner Dashboard"
        subtitle="A centralized hub designed to give you complete control and visibility over your business operations."
      />

      {/* Stats */}
      <div className="flex gap-4 my-8">

        {/* Total Bookings */}
        <div className="bg-gray-900/50 border border-gray-200/40 ml-4 rounded-xl flex p-4 pr-8">
          <img src={assets.totalBookingIcon} alt="total-bookings" className="max-sm:hidden h-10" />
          <div className="flex flex-col sm:font-medium ml-4">
            <p className="text-blue-600 text-lg">Total Bookings</p>
            <p className="text-gray-200 text-base">
              {dashboard.totalBookings}
            </p>
          </div>
        </div>

        {/* Total Revenue */}
        <div className="bg-gray-900/50 border border-gray-200/40 ml-4 rounded-xl flex p-4 pr-8">
          <img src={assets.totalRevenueIcon} alt="total-revenue" className="max-sm:hidden h-10" />
          <div className="flex flex-col sm:font-medium ml-4">
            <p className="text-blue-600 text-lg">Total Revenue</p>
            <p className="text-gray-200 text-base">
              {currency}{dashboard.totalRevenue}
            </p>
          </div>
        </div>

      </div>

      {/* Recent Bookings */}
      <h2 className="text-xl text-blue-500 font-medium mb-5">Recent Bookings</h2>

      <div className="w-full max-w-3xl text-left border border-gray-900 rounded-lg max-h-80 overflow-y-scroll">
        <table className="w-full">
          <thead className="bg-gray-900">
            <tr>
              <th className="py-3 px-4 text-white font-medium">User Name</th>
              <th className="py-3 px-4 text-white font-medium max-sm:hidden">Room Name</th>
              <th className="py-3 px-4 text-white font-medium text-center">Total Amount</th>
              <th className="py-3 px-4 text-white font-medium text-center">Payment Status</th>
            </tr>
          </thead>

          <tbody className="text-sm">
            {dashboard.bookings.length === 0 && (
              <tr>
                <td colSpan="4" className="py-4 text-center text-gray-400">
                  No bookings found
                </td>
              </tr>
            )}

            {dashboard.bookings.map((item, index) => (
              <tr key={index}>
                <td className="py-3 px-4 text-gray-200 border-t border-gray-300">
                  {item.user?.username}
                </td>

                <td className="py-3 px-4 text-gray-200 border-t border-gray-300 max-sm:hidden">
                  {item.room?.roomType}
                </td>

                <td className="py-3 px-4 text-gray-200 border-t border-gray-300 text-center">
                  {currency}{item.totalPrice}
                </td>

                <td className="py-3 px-4 border-t border-gray-400 text-center">
                  <span
                    className={`py-1 px-3 text-xs rounded-full ${
                      item.isPaid
                        ? 'bg-green-400 text-black'
                        : 'bg-amber-400 text-black'
                    }`}
                  >
                    {item.isPaid ? 'Completed' : 'Pending'}
                  </span>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </div>
  )
}

export default Dashboard
