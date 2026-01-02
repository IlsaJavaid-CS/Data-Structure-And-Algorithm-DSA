import User from "../models/User.js";

export const protect = async (req, res, next) => {
  try {
    if (!req.auth?.userId) {
      return res.status(401).json({
        success: false,
        message: "Not authenticated",
      });
    }

    const user = await User.findOne({
      clerkUserId: req.auth.userId, // MATCH MODEL
    });

    if (!user) {
      return res.status(404).json({
        success: false,
        message: "User not found in database",
      });
    }

    req.user = user;
    next();
  } catch (error) {
    res.status(500).json({ success: false, message: error.message });
  }
};
