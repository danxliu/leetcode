var expect = function(val) {
    var object = {};
    object.toBe = (val2) => {
        if (val === val2) {
            return true;
        }
        throw new Error("Not Equal");
    }
    object.notToBe = (val2) => {
        if (val !== val2) {
            return true;
        }
        throw new Error("Equal");
    }

    return object;
};