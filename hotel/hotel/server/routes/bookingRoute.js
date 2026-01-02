import express from "express";
import { checkAvailabilityAPI, createBooking, getHotelBookings, getUserBookings } from "../controllers/BookingControlleers.js";
import { protect } from "../middlewares/authmiddleware.js";

const bookingRoute = express.Router();
bookingRoute.post('/check-availability' , checkAvailabilityAPI);
bookingRoute.post('/book' , protect, createBooking);
bookingRoute.get('/user' , protect,  getUserBookings);
bookingRoute.get('/hotel' ,protect , getHotelBookings );

export default bookingRoute;