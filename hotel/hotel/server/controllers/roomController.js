
import { Message, messageInRaw } from "svix/dist/api/message.js";
import Hotel from "../models/Hotel.js";
import {v2 as cloudinary} from "cloudinary";
import Room from "../models/Room.js";
import { json } from "express";




// api to create a new room for a hotel
export const createRoom = async (req ,res )=>{
 try {
    const {roomType , pricePerNight , amenities} = req.body;
    const hotel = await Hotel.findOne({owner: req.auth().userId})
    if(!hotel) return res.json({success: false , Message: "No hotel found"});
    // upload images to cloudinary
    const uploadImage = req.files.map(async (File) => {
        const response = await cloudinary.uploader.upload(File.path);
        return response.secure_url;
    })
    // wait for all uploads to complete
   const images= await Promise.all(uploadImage)

    await Room.create({
        hotel: hotel._id,
        roomType,
        pricePerNight: +pricePerNight,   // will convert it in number
        amenities: JSON.parse(amenities),
        images,

    })
    res.json({success: true , message: "Room Created Successfully"} )
 } catch (error) {
      res.json({success: false , message: error.message} )
 }
}



// api to get all rooms
export const getRooms = async (req , res) =>{
    try {
        const rooms = await Room.find({isAvailable: true}).populate({
            path: 'hotel',
            populate:{
                path: 'owner',
                select: 'image'
            }
        }).sort({
            createdAt: -1
        })
        res.json({success: true , rooms})
    } catch (error) {
         res.json({success: false , message: error.message})
    }
}


// api to get all rooms for a specific hotel


export const getOwnerRooms = async (req , res)=>{
    try {
        const hotleData = await Hotel.findOne({owner: req.auth().userId})
        const rooms = await Room.find({hotel: hotleData._id.toString()}).populate("hotel");
        res.json({success: true , rooms});
    } catch (error) {
          res.json({success: false , message: error.message})
    }
}


// api to \toggle availability of the room 
export const toggleAvalability = async (req , res)=>{
    try {
        const {roomId} = req.body;
        const roomData = await Room.findById(roomId);
        roomData.isAvailable = !roomData.isAvailable;
        await roomData.save();
        res.json({success: true , message: "Room availability Updated"
        })
    } catch (error) {
           res.json({success: false , message: error.message})
    }

};