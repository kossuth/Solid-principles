from principles.srp.base import Srp
from principles.ocp.base import Ocp
from principles.lsp.base import Lsp

def main():
    srp = Srp()
    srp.start_principle()

    ocp = Ocp()
    ocp.start_principle()

    lsp = Lsp()
    lsp.start_principle()


if __name__ == "__main__":
    main()


# learn about naming
# https://www.python.org/dev/peps/pep-0008/#method-names-and-instance-variables
