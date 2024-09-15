const User = require("../models/User");

async function createUser( email, hashedPassword, skills) {
    const newUser = new User({
        email,
        hashedPassword,
        skills,
    });
    await newUser.save();
    return newUser;
};

async function getUserByEmail(email) {
    let userRegEx = new RegExp(`^${email}$`, "i");
    const currUser = await User.findOne({email:{$regex: userRegEx}});
    return currUser;
};

module.exports = {
    createUser,
    getUserByEmail
};