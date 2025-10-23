/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    const directoryStack = [];

    const components = path.split('/');

    for (const component of components) {
        if (component === '' || component === '.') { // Cur Dir
            continue;
        }

        if (component === '..') {
            if (directoryStack.length > 0) {
                directoryStack.pop();
            }
        } else {
            directoryStack.push(component);
        }
    }
    return '/' + directoryStack.join('/');
}