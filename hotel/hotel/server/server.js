import "dotenv/config";
import express from "express";
import cors from "cors";
import connectDB from "./config/db.js";
import connectCloudinary from "./config/cloudinary.js";
import { clerkMiddleware } from "@clerk/express";
import webhookRoutes from "./routes/webhookRoutes.js";
import clerkwebhooks from "./controllers/clerkWebhooks.js";
import userRouter from "./routes/userRoute.js";
import HotelRouter from "./routes/HotelRoutes.js";
import roomRouter from "./routes/RoomRoute.js";
import bookingRoute from "./routes/bookingRoute.js";

const app = express();

// DB & Cloudinary
connectDB();
connectCloudinary();
app.use("/api", webhookRoutes);

app.use(cors());

// ---------------------
// 🔴 CLERK WEBHOOK (RAW BODY ONLY)
app.use(
  "/api/clerk",
  express.raw({ type: "application/json" }),
  clerkwebhooks
);
// ---------------------

// JSON parser for rest
app.use(express.json());

// ✅ APPLY CLERK AUTH GLOBALLY (THIS WAS MISSING)
app.use(clerkMiddleware());

// Test route
app.get("/", (req, res) => {
  res.send("API is working fine now");
});

// APIs
app.use("/api/user", userRouter);
app.use("/api/hotels", HotelRouter);
app.use("/api/rooms", roomRouter);
app.use("/api/bookings", bookingRoute);

const PORT = process.env.PORT || 3000;
app.listen(PORT, () =>
  console.log(`Server running at http://localhost:${PORT}`)
);
