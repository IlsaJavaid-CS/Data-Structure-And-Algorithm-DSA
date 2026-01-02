import mongoose from "mongoose";

const userSchema = new mongoose.Schema(
  {
    clerkUserId: {
      type: String,
      required: true,
      unique: true,
    },

    firstName: String,
    lastName: String,
    email: String,
    image: String,

    role: {
      type: String,
      enum: ["User", "HotelOwner"],
      default: "User",
    },

    recentSearchedCities: {
      type: [String],
      default: [],
    },
  },
  { timestamps: true }
);

export default mongoose.model("User", userSchema);
