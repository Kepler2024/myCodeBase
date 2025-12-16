import time
from contextlib import contextmanager
from functools import wraps
from typing import Iterator

# 装饰器：给函数加点“魅力”
def seduce(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        print("💋 ", end="")
        result = func(*args, **kwargs)
        print(" 💋")
        return result
    return wrapper

# 上下文管理器：制造氛围
@contextmanager
def flirt(duration: float = 1.0):
    print("💓💓💓 Flirting begins... 💓💓💓")
    start = time.time()
    yield
    elapsed = time.time() - start
    print(f"💓 Flirting ends after {elapsed:.2f}s 💓")

# 生成器：层层递进的心形
def heart_generator(max_size: int = 9) -> Iterator[str]:
    for size in range(1, max_size, 2):
        yield f'{"❤️" * size:^20}'

# 使用示例
@seduce
def whisper(message: str) -> None:
    print(f"*whispers* “{message}”")

with flirt(2.0):
    for heart in heart_generator():
        print(heart)
        time.sleep(0.2)
    whisper("你让我心跳加速…")