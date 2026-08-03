class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs: string[]): string {
        if (strs.length === 0) return "$$EMPTY$$$LIST$$";
        return strs.join("#$7777777$#");
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str: string): string[] {
        if (str === "$$EMPTY$$$LIST$$") return [];
        return str.split("#$7777777$#");
    }
}
