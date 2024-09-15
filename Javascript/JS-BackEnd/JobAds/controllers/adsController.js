const router = require("express").Router();
const { isGuest, isUser, isOwner } = require("../middlewares/guards");

router.get("/", async(req, res) => {

    let allAds = await req.storage.getAll();

    res.render("home.hbs", {allAds});
});

router.get("/all-ads", async(req, res) => {
    let allAds = await req.storage.getAll();
    res.render("all-ads.hbs", {allAds});
});

router.get("/delete/:id", isUser(), isOwner(), async(req, res) => {
    await req.storage.del(req.params.id);
    res.redirect("/");
});

router.get("/edit/:id", isUser(), isOwner(), async(req, res) => {
    let currItem = await req.storage.getById(req.params.id);
    res.render("edit.hbs", {info: currItem});

});

router.post("/edit/:id", isUser(), isOwner(), async(req, res) => {
    let data = {
        headline: req.body.headline,
        location: req.body.location,
        companyName: req.body.companyName,
        companyDescription: req.body.companyDescription,
        author: req.user._id,

    };
    try {
        let errors = [];
        if(req.body.headline.length < 4) {
            errors.push("Headline must be 4 chars or more!");
        }
        if(req.body.location.length < 8) {
            errors.push("Headline must be 8 chars or more!");
        }
        if(req.body.companyName.length < 3) {
            errors.push("Company name be 4 chars or more!");
        }
        if(req.body.companyDescription.length < 40) {
            errors.push("Company description must be 40 chars or more!");
        }

        await req.storage.edit(req.params.id, data);
        res.redirect(`/details/${req.params.id}`);
    }catch(err) {
        console.log(err);
        res.render("edit.hbs", {errors: err.message.split("\n"), info: data});
    }
});

router.get("/details/:id", isUser(), async(req, res) => {
    let currAd = await req.storage.getById(req.params.id);
    currAd.owner = currAd.author.email;

    let hasApplied = currAd.applies.find(x => x._id == req.user._id);

    if(currAd.author._id == req.user._id) {
        currAd.isOwner = true;
    }
    if(hasApplied) {
        currAd.hasApplied = true;
    }
    res.render("details.hbs", currAd);
});

router.get("/apply/:id", isUser(), async(req, res) => {
    await req.storage.apply(req.params.id, req.user._id);
    res.redirect(`/details/${req.params.id}`);
});

router.get("/create", isUser(), (req, res) => {
    res.render("create.hbs");
});

router.post("/create", isUser(), async(req, res) => {
    let data = {
        headline: req.body.headline,
        location: req.body.location,
        companyName: req.body.companyName,
        companyDescription: req.body.companyDescription,
        author: req.user._id,

    };
    try {
        let errors = [];
        if(req.body.headline.length < 4) {
            errors.push("Headline must be 4 chars or more!");
        }
        if(req.body.location.length < 8) {
            errors.push("Headline must be 8 chars or more!");
        }
        if(req.body.companyName.length < 3) {
            errors.push("Company name be 4 chars or more!");
        }
        if(req.body.companyDescription.length < 40) {
            errors.push("Company description must be 40 chars or more!");
        }

        if(errors.length > 0) {
            throw new Error(errors.join("\n"));
        }

        await req.storage.create(data);
        res.redirect("/");
    }catch(err) {
        console.log(err);
        res.render("create.hbs", {errors: err.message.split("\n")});
    }
});

router.get("/search", async(req, res) => {
    res.render("search.hbs");
});

router.all("*", (req, res) => {
    res.render("404.hbs");
});


module.exports = router;