try:
    from primitiv.devices.cuda_device import _CUDA as CUDA
except ModuleNotFoundError:
    pass
from primitiv.devices.naive_device import _Naive as Naive

__all__ = [
    "CUDA",
    "Naive",
]
