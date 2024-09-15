const adService = require("../services/ad");

module.exports = () => {
    return (req, res, next) => {
        req.storage = {
            create: adService.create,
            getById: adService.getById,
            getAll: adService.getAll,
            del: adService.del,
            edit: adService.edit,
            apply: adService.apply,
        };


        next();
    };
}