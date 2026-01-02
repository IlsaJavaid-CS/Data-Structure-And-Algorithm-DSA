import express from "express";
import clerkWebhooks from "../controllers/clerkWebhooks.js";

const router = express.Router();

router.post(
  "/clerk",
  express.json({ type: "application/json" }),
  clerkWebhooks
);

export default router;
