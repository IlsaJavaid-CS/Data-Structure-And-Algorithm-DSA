import express from "express";

import { protect } from "../middlewares/authmiddleware.js";
import { registerHotel } from "../controllers/HotelController.js";

const HotelRouter = express.Router();

// HotelRouter.post('/'
//      , protect 
//     , registerHotel);

// HotelRouter.post("/", (req, res) => {
//   console.log("Hotel route hit!", req.body);
//   res.json({ success: true, message: "Hotel registered!" });
// });


HotelRouter.post("/", (req, res) => {
  console.log("Hotel route hit!", req.body);
  res.json({ success: true, message: "Hotel registered successfully!" });
});



export default HotelRouter;
