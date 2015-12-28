/**
 * Created by sotetsuk on 2015/12/27.
 */
object A {
  def main(args: Array[String]) {
    val N = readInt()
    var ans = 0.0
    for(i <- 1 to N) {
      ans += 1.0 * i / N
    }
    println(ans * 10000)
  }
}
