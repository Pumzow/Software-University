const express = require("express");
const hbs = require("express-handlebars");
const cookieParser = require("cookie-parser");
const authMiddleware = require("../middlewares/auth");
const adsMiddleware = require("../middlewares/ad");

module.exports = (app) => {
    app.engine("hbs", hbs.engine({
        extname: "hbs"
    }));
    app.use("/static", express.static("static"));
    app.use(express.urlencoded({extended: true}));
    app.use(cookieParser());
    app.use(authMiddleware());
    app.use(adsMiddleware());
};