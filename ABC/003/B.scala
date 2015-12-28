/**
 * Created by sotetsuk on 2015/12/28.
 */
object B {
  def main(args: Array[String]) {
    val s = readLine()
    val t = readLine()

    var flag = true
    for((a, b) <- (s zip t)) {
      if(a != b) {
        if(!(a == '@' || b == '@')) flag = false
        if(!("atcoder".contains(a) || "atcoder".contains(b))) flag = false
      }
    }
    val ans = if(flag) "You can win" else "You will lose"
    println(ans)
  }
}
