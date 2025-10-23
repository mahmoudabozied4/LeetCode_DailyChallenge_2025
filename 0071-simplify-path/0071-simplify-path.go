func simplifyPath(path string) string {
 	var directoryStack []string

 	pathComponents := strings.Split(path, "/")

	for _, component := range pathComponents {
 		if component == "" || component == "." {
			continue
		}

 		if component == ".." {
 			if len(directoryStack) > 0 {
				directoryStack = directoryStack[:len(directoryStack)-1]
			}
		} else {
 			directoryStack = append(directoryStack, component)
		}
	}
 	return "/" + strings.Join(directoryStack, "/")
}