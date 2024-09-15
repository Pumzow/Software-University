const Ad = require("../models/Ad");


    async function create(data) {
        let newItem = new Ad(data);

        await newItem.save();
        return newItem;
    };

    async function getAll(criteria) {
        let search = {};

        if(criteria != undefined) {
            search = criteria;
        };

        let allAds = await Ad.find(search).populate("applies").limit(3).lean();
        return allAds;
    };
    
    async function getSearchResult(searchEmail) {

        let searchAds = await Ad.find(a => a.author.email = searchEmail).lean();
        return searchAds;
    };

    async function getById(id) {
        let currAd = await Ad.findById(id).populate("author").lean();
        return currAd;
    }

    async function edit(id, data) {
        let currAd = await Ad.findById(id);
        currAd = Object.assign(currAd, data);
        await currAd.save();
        return currAd;
    }

    async function del(id) {
        await Ad.deleteOne({_id: id});
    };

    async function apply(id, userId) {
        let currAd = await Ad.findById(id);
        currAd.applies.push(userId);
        await currAd.save();
    };

module.exports = {
    create,
    getById,
    getAll,
    edit,
    del,
    apply,
};