import { Webhook } from "svix";
import User from "../models/User.js";

const clerkWebhooks = async (req, res) => {
  try {
    const payload = JSON.stringify(req.body);
    const headers = req.headers;

    const wh = new Webhook(process.env.CLERK_WEBHOOK_SECRET);

    const evt = wh.verify(payload, {
      "svix-id": headers["svix-id"],
      "svix-timestamp": headers["svix-timestamp"],
      "svix-signature": headers["svix-signature"],
    });

    if (evt.type === "user.created") {
      const user = evt.data;

      // ✅ Safely handle missing email
      const email =
        user.email_addresses && user.email_addresses.length > 0
          ? user.email_addresses[0].email_address
          : "no-email@example.com";

      await User.create({
        clerkUserId: user.id, // MUST exist
        firstName: user.first_name || "",
        lastName: user.last_name || "",
        email:
         user.email_addresses?.[0]?.email_address ||
          "no-email@example.com",

        image: user.image_url || "",
      });

      console.log("User saved to MongoDB:", user.id);
    }

    res.status(200).json({ success: true });
  } catch (error) {
    console.error("Webhook Error:", error.message);
    res.status(500).json({ success: false, message: error.message });
  }
};

export default clerkWebhooks;
