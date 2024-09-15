const authController = require("../controllers/authController");
const adsController = require("../controllers/adsController");

module.exports = (app) => {
    app.use("/auth", authController);
    app.use("/", adsController);
};