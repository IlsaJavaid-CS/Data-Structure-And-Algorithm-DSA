import express from "express";
import upload from "../middlewares/uploadMiddleware.js";
import { protect } from "../middlewares/authmiddleware.js";
import { createRoom, getOwnerRooms, getRooms, toggleAvalability } from "../controllers/roomController.js";


const roomRouter = express.Router();
roomRouter.post('/' , upload.array("images" , 4) , protect , createRoom);
roomRouter.get('/' , getRooms)
roomRouter.get('/owner' , protect , getOwnerRooms)
roomRouter.post('/toggle-availability' , protect , toggleAvalability)

export default roomRouter;