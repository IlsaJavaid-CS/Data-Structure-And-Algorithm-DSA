import express from "express";
import { protect } from "../middlewares/authmiddleware.js";
import { getUserData, storeRecentSearchedCities } from "../controllers/usercontroller.js";


const userRouter = express.Router();

userRouter.get('/' , protect, getUserData)
userRouter.post('/store-recent-search' , protect, storeRecentSearchedCities )

export default userRouter;
