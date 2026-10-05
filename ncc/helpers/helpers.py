def read_file(path:str) -> str: 
    with open(path, "r") as f:
        file = f.read()
    return file