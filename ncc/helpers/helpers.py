import subprocess, os, sys

def read_file(path:str) -> str: 
    with open(path, "r", encoding="utf-8") as f:
        return f.read()

def write_asm(assembly:str, output_name:str) -> None:
    with open("temp.s", "w", encoding="utf-8") as f:
        f.write(assembly)

    result = subprocess.run(["gcc", "temp.s", "-o", output_name], check=True)
    if result.returncode: sys.exit(result.returncode)

    os.remove("temp.s")