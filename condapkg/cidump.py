import argparse
import certinfo
from termcolor import cprint

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-u", "--url", default="https://www.google.com", help="Site to show certs for")
    args = parser.parse_args()
    dump = certinfo.dump(args.url)
    for i, lines in enumerate(dump):
        cprint(f">>> CBEGIN {i+1}/{len(dump)}", "green")
        print("\n".join(lines))
        cprint(f">>> CEND {i+1}/{len(dump)}", "green")
